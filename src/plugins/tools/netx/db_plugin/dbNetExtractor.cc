
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2018 Matthias Koefferlein

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


#include "dbNetExtractor.h"
#include "dbHierProcessor.h"
#include "dbLayoutUtils.h"
#include "dbCellMapping.h"
#include "dbPolygonTools.h"
#include "dbBoxScanner.h"
#include "dbRecursiveShapeIterator.h"
#include "dbBoxConvert.h"
#include "tlLog.h"

namespace db
{

NetExtractor::NetExtractor()
  : mp_orig_layout (0), mp_layout (0), mp_top_cell (0), m_nthreads (0)
{

  // @@@

}

NetExtractor::~NetExtractor ()
{
  delete mp_layout;
  mp_layout = 0;
  mp_top_cell = 0;
}

void
NetExtractor::set_threads (unsigned int nthreads)
{
  m_nthreads = nthreads;
}

void
NetExtractor::open (const db::Layout &orig_layout, cell_index_type orig_top_cell)
{
  tl::SelfTimer timer (tl::verbosity () >= 31, tl::to_string (tr ("Open layout")));

  delete mp_layout;
  mp_orig_layout = &orig_layout;

  mp_layout = new db::Layout ();
  mp_layout->dbu (orig_layout.dbu ());
  mp_top_cell = &mp_layout->cell (mp_layout->add_cell (orig_layout.cell_name (orig_top_cell)));

  //  copy hierarchy
  m_cm.clear ();
  m_cm.create_from_names_full (*mp_layout, mp_top_cell->cell_index (), orig_layout, orig_top_cell);
}

void
NetExtractor::output (NetLayer a, const LayerProperties &lp)
{
  mp_layout->set_properties (a.layer_index (), lp);
}

static double area_ratio (const db::Polygon &poly)
{
  return double (poly.box ().area ()) / double (poly.area ());
}

static void split_polygon_into (const db::Polygon &poly, db::Shapes &dest, size_t max_points, double max_area_ratio)
{
  size_t npoints = 0;
  for (unsigned int c = 0; c < poly.holes () + 1; ++c) {
    npoints += poly.contour (c).size ();
  }

  if (npoints > max_points || area_ratio (poly) > max_area_ratio) {

    std::vector <db::Polygon> split_polygons;
    db::split_polygon (poly, split_polygons);
    for (std::vector <db::Polygon>::const_iterator sp = split_polygons.begin (); sp != split_polygons.end (); ++sp) {
      split_polygon_into (*sp, dest, max_points, max_area_ratio);
    }

  } else {

    dest.insert (db::PolygonRef (poly, dest.layout ()->shape_repository ()));

  }
}

NetLayer
NetExtractor::load (unsigned int layer_index)
{
  tl::SelfTimer timer (tl::verbosity () >= 31, tl::to_string (tr ("Loading layer ")) + mp_orig_layout->get_properties (layer_index).to_string ());

  const double max_area_ratio = 3.0;
  const size_t max_points = 16;

  NetLayer lt (mp_layout->insert_layer ());
  mp_layout->set_properties (lt.layer_index(), mp_orig_layout->get_properties (layer_index));

  for (db::Layout::const_iterator c = mp_orig_layout->begin (); c != mp_layout->end (); ++c) {

    if (m_cm.has_mapping (c->cell_index ())) {

      db::cell_index_type ct = m_cm.cell_mapping (c->cell_index ());

      db::Shapes &dest_shapes = mp_layout->cell (ct).shapes (lt.layer_index());
      const db::Shapes &orig_shapes = c->shapes (layer_index);
      for (db::Shapes::shape_iterator s = orig_shapes.begin (db::ShapeIterator::Polygons | db::ShapeIterator::Paths | db::ShapeIterator::Boxes); ! s.at_end (); ++s) {

        //  @@@ TODO: cache splitting and path to polygon conversion
        db::Polygon poly;
        s->polygon (poly);

        split_polygon_into (poly, dest_shapes, max_points, max_area_ratio);

      }

    }

  }

  return lt;
}

NetLayer
NetExtractor::bool_and (NetLayer a, NetLayer b)
{
  return and_or_not (a, b, true);
}

NetLayer
NetExtractor::bool_not (NetLayer a, NetLayer b)
{
  return and_or_not (a, b, false);
}

NetLayer
NetExtractor::and_or_not (NetLayer a, NetLayer b, bool is_and)
{
  unsigned int lout = mp_layout->insert_layer ();

  db::BoolAndOrNotLocalOperation op (is_and);
  db::LocalProcessor proc (mp_layout, mp_top_cell);
  proc.set_threads (m_nthreads);
  proc.run (&op, a.layer_index (), b.layer_index (), lout);

  return NetLayer (lout);
}

db::Layout *
NetExtractor::layout_copy () const
{
  tl_assert (mp_layout != 0);
  return new db::Layout (*mp_layout);
}

}

