// Fredit: A fresh editor.
//
// Copyright (C) 2009 Diwaker Gupta <diwaker@floatingsun.net>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

#ifndef FREDIT_CORE_CURSOR_H_
#define FREDIT_CORE_CURSOR_H_

// A Cursor stores the cursor position.
//
// It is essentially a QPoint with some additional methods required by
// fred-core.
// 
// The Cursor comparator is designed such that given:
// x1 < x2 and y1 < y2, we have
// Cursor(x1, y1) < Cursor(x2, y2)
// Cursor(x2, y1) < Cursor(x1, y2)

#include <QPoint>
#include <QString>

namespace fredit { namespace core {

class Cursor : public QPoint {
 public:
  Cursor(): QPoint(0, 0) {}
  Cursor(const QPoint& p): QPoint(p) {}
  Cursor(int x, int y): QPoint(x, y) {}

  void SetXY(int x, int y) {
    setX(x);
    setY(y);
  }

  // Aliases: "line" refers to the Y axis, "column" refers to the X axis.
  inline void set_line(int line) { setY(line); }
  inline int line() const { return y(); }

  inline void set_column(int column) { setX(column); }
  inline int column() const { return x(); }

  inline int SetLineColumn(int line, int column) { SetXY(column, line); }

  QString toString() const {
    return QString("(line, col) = (%1, %2)").arg(line()).arg(column());
  }

  // Operators. Note that QT implements the == and != operators.
  bool operator<(const Cursor& right) const;
  bool operator<=(const Cursor& right) const;
  bool operator>(const Cursor& right) const;
  bool operator>=(const Cursor& right) const;
};
  
} } // end namespace

#endif // end of include guard: FREDIT_CORE_CURSOR_H_
