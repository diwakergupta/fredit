// Fredit: A fresh editor.

// Copyright (C) 2010 Diwaker Gupta <diwaker@floatingsun.net>

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

// qt.
#include <QString>

// google-test.
#include <gtest/gtest.h>

namespace core = fredit::core;

TEST(CursorTest, Construction) {
  core::Cursor cursor;
  cursor.SetXY(10, 10);
  ASSERT_TRUE(cursor == core::Cursor(10, 10));
}

TEST(CursorTest, Comparators) {
  core::Cursor cursor1(10, 10), cursor2(10, 20), cursor3(20, 10);

  ASSERT_TRUE(cursor1 < cursor2);
  ASSERT_TRUE(cursor1 < cursor3);
  ASSERT_TRUE(cursor3 < cursor2);
}

TEST(CursorTest, API) {
  core::Cursor cursor(2, 3);

  ASSERT_TRUE(cursor.toString() == QString("(line, col) = (3, 2)"));

  cursor.SetXY(3, 2);
  ASSERT_EQ(cursor.line(), 2);
  ASSERT_EQ(cursor.column(), 3);

  cursor.SetLineColumn(3, 2);
  ASSERT_EQ(cursor.line(), 3);
  ASSERT_EQ(cursor.column(), 2);
}
