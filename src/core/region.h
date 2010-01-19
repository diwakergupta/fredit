// Fredit: A fresh editor.

// Copyright (c) 2010 Diwaker Gupta <diwaker@floatingsun.net>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

// A Region is simply a frament of the buffer bounded by two Cursor positions.

#ifndef FRED_CORE_REGION_H_
#define FRED_CORE_REGION_H_

#include <QString>
#include <QRect>

#include "core/cursor.h"

namespace fredit { namespace core {

class Region {
 public:
  // Constructors.
  Region(const Cursor& from, const Cursor& to);
  Region(const QRect& r);
  Region();

  const Cursor& from() const { return from_; }
  void set_from(const Cursor& from) { from_ = from; }

  const Cursor& to() const { return to_; }
  void set_to(const Cursor& to) { to_ = to; }

  // Return true if Cursor at location 'loc' is contained in this region.
  bool Contains(const Cursor& loc) const;

  // Return true if Region 'region' is contained in this region.
  bool Contains(const Region& region) const;

  // Return true if Region 'region' overlaps with this region.
  bool Overlaps(const Region& region) const;

  // Return the intersection of Region 'region' with this region.
  Region Intersect(const Region& region) const;

  // Return the bounding rectangle for this region.
  QRect GetBoundingRect() const;

 private:
  Cursor from_;
  Cursor to_;
};

} } 

#endif // end of include guard: FRED_CORE_REGION_H_
