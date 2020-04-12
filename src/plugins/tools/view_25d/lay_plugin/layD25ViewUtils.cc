
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2020 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#include "layD25ViewUtils.h"

#include <QMatrix4x4>
#include <QMatrix3x3>

#include <math.h>

namespace lay
{

const double epsilon = 1e-10;

std::pair<bool, QVector3D>
cutpoint_line_with_plane (const QVector3D &line, const QVector3D &dir, const QVector3D &plane, const QVector3D &plane_normal)
{
  double dn = QVector3D::dotProduct (dir, plane_normal);
  if (fabs (dn) < epsilon) {
    return std::make_pair (false, QVector3D ());
  } else {
    return std::make_pair (true, line + dir * QVector3D::dotProduct (plane - line, plane_normal) / dn);
  }
}

std::pair<bool, QVector3D>
cutpoint_line_with_face (const QVector3D &line, const QVector3D &dir, const QVector3D &plane, const QVector3D &u, const QVector3D &v)
{
  QVector3D n = QVector3D::crossProduct (u, v);
  std::pair<bool, QVector3D> r = cutpoint_line_with_plane (line, dir, plane, n);
  if (! r.first) {
    return r;
  }

  double pu = QVector3D::dotProduct (r.second - plane, u);
  double pv = QVector3D::dotProduct (r.second - plane, v);

  //  test whether the cut point is inside the face
  if (pu < -epsilon || pu > u.lengthSquared () + epsilon || pv < -epsilon || pv > v.lengthSquared () + epsilon) {
    return std::make_pair (false, QVector3D ());
  } else {
    return r;
  }
}

static std::pair<bool, QVector3D> plane_or_face (const QVector3D &line, const QVector3D &line_dir, const QVector3D &corner, const QVector3D &u, const QVector3D &v, bool face)
{
  if (face) {
    return cutpoint_line_with_face (line, line_dir, corner, u, v);
  } else {
    return cutpoint_line_with_plane (line, line_dir, corner, QVector3D::crossProduct (u, v));
  }
}

std::pair<bool, QVector3D>
hit_point_with_cuboid (const QVector3D &line, const QVector3D &line_dir, const QVector3D &corner, const QVector3D &dim)
{
  std::vector<std::pair<bool, QVector3D> > cutpoints;
  cutpoints.reserve (6);  //  6 faces

  for (int pass = 0; pass < 2; ++pass) {

    bool face = (pass == 0);

    if (face) {
      bool in_x = (line.x () > corner.x () - epsilon) && (line.x () < corner.x () + dim.x () + epsilon);
      bool in_y = (line.y () > corner.y () - epsilon) && (line.y () < corner.y () + dim.y () + epsilon);
      bool in_z = (line.z () > corner.z () - epsilon) && (line.z () < corner.z () + dim.z () + epsilon);
      if (in_x && in_y && in_z) {
        //  inside cuboid
        return std::make_pair (true, line);
      }
    }

    cutpoints.clear ();

    //  front
    cutpoints.push_back (plane_or_face (line, line_dir, corner, QVector3D (dim.x (), 0, 0), QVector3D (0, dim.y (), 0), face));
    //  back
    cutpoints.push_back (plane_or_face (line, line_dir, corner + QVector3D (0, 0, dim.z ()), QVector3D (dim.x (), 0, 0), QVector3D (0, dim.y (), 0), face));

    if (face) {
      //  bottom
      cutpoints.push_back (plane_or_face (line, line_dir, corner, QVector3D (dim.x (), 0, 0), QVector3D (0, 0, dim.z ()), face));
      //  top
      cutpoints.push_back (plane_or_face (line, line_dir, corner + QVector3D (0, dim.y (), 0), QVector3D (dim.x (), 0, 0), QVector3D (0, 0, dim.z ()), face));
      //  left
      cutpoints.push_back (plane_or_face (line, line_dir, corner, QVector3D (0, 0, dim.z ()), QVector3D (0, dim.y (), 0), face));
      //  right
      cutpoints.push_back (plane_or_face (line, line_dir, corner + QVector3D (dim.x (), 0, 0), QVector3D (0, 0, dim.z ()), QVector3D (0, dim.y (), 0), face));
    }

    double min_dist = 0.0;
    int min_dist_index = -1;
    QVector3D ld_norm = line_dir.normalized ();

    for (std::vector<std::pair<bool, QVector3D> >::const_iterator i = cutpoints.begin (); i != cutpoints.end (); ++i) {
      if (i->first) {
        double dist = QVector3D::dotProduct (i->second - line, ld_norm);
        if (dist < -epsilon) {
          //  ignore all cutpoints behind us
        } else if (min_dist_index < 0) {
          min_dist = dist;
          min_dist_index = int (i - cutpoints.begin ());
        } else if (dist < min_dist) {
          min_dist = dist;
          min_dist_index = int (i - cutpoints.begin ());
        }
      }
    }

    if (min_dist_index >= 0) {
      return cutpoints [min_dist_index];
    }

  }

  return std::make_pair (false, QVector3D ());
}

std::pair<QVector3D, QVector3D>
camera_normal (const QMatrix4x4 &camera_trans, double x, double y)
{
  QVector3D p = camera_trans.inverted ().map (QVector3D (x, y, 1.0));

  QVector4D pv = camera_trans.row (3);

  QMatrix4x4 m (camera_trans);

  float values[] = {
    float (x * pv.x ()),  float (x * pv.y ()),  float (x * pv.z ()),  0.0f,
    float (y * pv.x ()),  float (y * pv.y ()),  float (y * pv.z ()),  0.0f,
    float (pv.x ()),      float (pv.y ()),      float (pv.z ()),      0.0f,
    0.0f,                 0.0f,                 0.0f,                 0.0f
  };
  m -= QMatrix4x4 (values);

  QMatrix3x3 nm = m.normalMatrix ();

  QVector3D u (nm (2, 0), nm (2, 1), nm (2, 2));
  return (std::make_pair (p, u.normalized ()));
}

void
normalize_scene_trans (const QMatrix4x4 &cam_trans, QVector3D &displacement, double &scale, double ztarget)
{
  QMatrix4x4 m;

  //  Here is the theory:
  //  Let:
  //    cam = (  M  t  )     M = 3x3 matrix, t = 3x1 translation vector, z = scalar, p = 1x3 perspective
  //          (  p  z  )
  //  and:
  //    scene = (  S  d  )   S = s*U1  (s = scale factor, U1 = 3x3 unit matrix), d = 3x1 displacement vector
  //            (  0  1  )
  //  then:
  //    cam * scene = (  M*s   M*d+t  )
  //                  (  p*s   p*d+z  )    (p*d = dot product)
  //
  //  this is image invariant (only x,y results are considered) against changes of s (s->s') if
  //
  //    1.) (p*d+z)/s = (p*d'+z)/s'
  //    2.) (M*d+t)/s = (M*d'+t)/s'  for  [x] and [y]
  //
  //  Ff we seek a solution with d'[z] == b  (b = ztarget), we get these equations (f:=s'/s)
  //
  //    2.)   M[xx] * d'[x] + M[xy] * d'[y] - ((M*d)[x] + t[x]) * f = -t[x] - M[xz] * b
  //          M[yx] * d'[x] + M[yy] * d'[y] - ((M*d)[y] + t[y]) * f = -t[y] - M[yz] * b
  //    1.)   p[x]  * d'[x] + p[y]  * d'[y] - (p*d+z)           * f = -z    - p[z] * b
  //
  //  we can solve these equations for d'[x], d'[y] and f.
  //  With p[x]=M[wx], p[y]=M[wy] and z=t[w], the above equation system can be written as
  //
  //          M[ix] * d'[x] + M[iy] * d'[y] - ((M*d)[i] + t[i]) * f = -t[i] - M[iz]*b   i = x,y,w
  //
  //  and with M,t->M (4x4 matrix) and d->(d,1) (4d vector)
  //
  //          M[ix] * d'[x] + M[iy] * d'[y] - (M*d)[i] * f = -t[i] - M[iz]*b   i = x,y,w
  //

  QVector4D d4 (displacement);
  d4.setW (1.0);

  for (int i = 0; i < 4; ++i) {
    if (i != 2) {
      m (i, 0) = cam_trans (i, 0);
      m (i, 1) = cam_trans (i, 1);
      m (i, 3) = -QVector4D::dotProduct (cam_trans.row (i), d4);
    }
  }

  bool invertable = false;
  m = m.inverted (&invertable);
  if (! invertable) {
    return;
  }

  QVector4D sol = m.map (-cam_trans.column (3) - cam_trans.column (2) * ztarget);
  if (sol.w () > 0.01 /*skip weird solutions*/) {
    scale *= sol.w ();
    displacement = QVector3D (sol.x (), sol.y (), ztarget);
  }
}

}