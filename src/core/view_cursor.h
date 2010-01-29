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

#ifndef FREDIT_CORE_VIEW_CURSOR_H_
#define FREDIT_CORE_VIEW_CURSOR_H_

// A ViewCursor encapsulates the position of the cursor in a view. Internally,
// it maintains a Cursor object that stores the cursor position in the
// associated buffer. However, because the column position on screen might
// differ from the actual column position in the buffer (due to word-wrapping,
// for instance), we additionally store the visible column position.

#include "core/cursor.h"

namespace fredit { namespace core {

class ViewCursor {
 public:
  ViewCursor();
  ViewCursor(int line, int column, int position);
  ViewCursor(const ViewCursor&);
  virtual ~ViewCursor();

  // Cursor info for the underlying buffer.
  inline int line() const { return cursor_.line(); }
  inline void set_line(int line) { cursor_.set_line(line); }

  inline int column() const { return cursor_.column(); }
  inline void set_column(int col) { cursor_.set_column(col); }

  inline int position() const { return position_; }
  inline void set_position(int pos) { position_ = pos; }

  // Operators.
 private:
  Cursor cursor_;
  // Position in the view (on the same line as cursor_.line()).
  int position_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_VIEW_CURSOR_H_
