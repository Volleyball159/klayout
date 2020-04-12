
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

#ifndef HDR_layD25ViewWidget
#define HDR_layD25ViewWidget

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QPoint>
#include <QVector3D>

#include "dbPolygon.h"

#include "layD25MemChunks.h"

namespace db
{
  class Layout;
  class Cell;
}

namespace lay
{

class LayoutView;

class D25ViewWidget
  : public QOpenGLWidget,
    private QOpenGLFunctions
{
Q_OBJECT 

public:
  D25ViewWidget (QWidget *parent);
  ~D25ViewWidget ();

  void keyPressEvent (QKeyEvent *event);
  void keyReleaseEvent (QKeyEvent *event);
  void wheelEvent (QWheelEvent *event);
  void mousePressEvent (QMouseEvent *event);
  void mouseReleaseEvent (QMouseEvent *event);
  void mouseMoveEvent (QMouseEvent *event);

  void attach_view (lay::LayoutView *view);

private:
  typedef lay::mem_chunks<GLfloat, 1024 * 9> chunks_type;

  QOpenGLShaderProgram *m_shapes_program, *m_gridplane_program;
  QMatrix4x4 m_cam_trans;
  bool m_dragging, m_rotating;
  double m_scale_factor;
  double m_cam_azimuth, m_cam_elevation;
  bool m_top_view;
  QVector3D m_displacement;
  double m_focus_dist;
  QPoint m_start_pos;
  QVector3D m_start_cam_position;
  double m_start_cam_azimuth, m_start_cam_elevation;
  QVector3D m_start_displacement;
  lay::LayoutView *mp_view;
  db::DBox m_bbox;
  double m_zmin, m_zmax;

  std::list<chunks_type> m_vertex_chunks;

  struct LayerInfo {
    const chunks_type *vertex_chunk;
    GLfloat color [4];
  };

  std::list<LayerInfo> m_layers;

  void initializeGL ();
  void paintGL ();
  void resizeGL (int w, int h);

  void update_cam_trans ();
  void prepare_view ();
  void render_layout (D25ViewWidget::chunks_type &chunks, const db::Layout &layout, const db::Cell &cell, unsigned int layer, double zstart, double zstop);
  void render_polygon (D25ViewWidget::chunks_type &chunks, const db::Polygon &poly, double dbu, double zstart, double zstop);
  void render_wall (D25ViewWidget::chunks_type &chunks, const db::Edge &poly, double dbu, double zstart, double zstop);
  QVector3D hit_point_with_scene(const QVector3D &line, const QVector3D &line_dir);
  double cam_elevation () const;
  double cam_azimuth () const;
  QVector3D cam_position () const;
  QVector3D cam_direction () const;
};

}

#endif
