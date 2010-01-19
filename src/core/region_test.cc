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

#include "core/cursor.h"
#include "core/region.h"

#include <gtest/gtest.h>

namespace core = fredit::core;

TEST(RegionTest, API) {
  //  c1----c3----c5---c7
  //  |     |     |    |
  //  |     |     |    |
  //  c2----c4----c6---c8

  core::Cursor c1(0, 0);
  core::Cursor c3(40, 0);
  core::Cursor c5(80, 0);
  core::Cursor c7(120, 0);

  core::Cursor c2(0, 40);
  core::Cursor c4(40, 40);
  core::Cursor c6(80, 40);
  core::Cursor c8(120, 40);

  core::Region r1(c1, c6);
  core::Region r2(c3, c8);
  core::Region r3(c3, c6);
  core::Region r4(c1, c8);

  ASSERT_TRUE(r4.Contains(r3));
  ASSERT_TRUE(r4.Contains(r1));
  ASSERT_TRUE(r4.Contains(r2));
  ASSERT_TRUE(r1.Contains(r3));
  ASSERT_TRUE(r2.Contains(r3));

  ASSERT_TRUE(r1.Overlaps(r2));
  ASSERT_TRUE(r2.Overlaps(r1));
  ASSERT_TRUE(r1.Overlaps(r4));
  ASSERT_TRUE(r4.Overlaps(r2));

  core::Region r5 = r1.Intersect(r2);
  ASSERT_TRUE(r5.from() == r3.from());
  ASSERT_TRUE(r5.to() == r3.to());
}
