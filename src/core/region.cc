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

#include "region.h"

#include <algorithm> // for min, max

namespace fredit { namespace core {

Region::Region(const Cursor& from, const Cursor& to)
    : from_(from), to_(to) {
}

Region::Region(const QRect& rect)
    : from_(Cursor(rect.left(), rect.top())),
      to_(Cursor(rect.right(), rect.bottom())) {
}

Region::Region() : from_(Cursor(0,0)), to_(Cursor(0,0)) {
}

bool Region::Contains(const Cursor& loc) const {
  return (from_ >= loc && loc <= to_);
}

bool Region::Contains(const Region& region) const {
  return (from_ <= region.from() && to_ >= region.to());
}

bool Region::Overlaps(const Region& region) const {
  return (Contains(region.from()) || Contains(region.to()) ||
          region.Contains(from_) || region.Contains(to_));
}

Region Region::Intersect(const Region& region) const {
  return Region(std::max(region.from(), from_),
                std::min(region.to(), to_));
}

QRect Region::GetBoundingRect() const {
  QRect rect;
  rect.setTop(from_.line());
  rect.setBottom(to_.line());
  rect.setLeft(std::min(from_.column(), to_.column()));
  rect.setRight(std::max(from_.column(), to_.column()));
}

} } // end namespace.
