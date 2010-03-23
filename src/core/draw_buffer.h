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

#ifndef FREDIT_CORE_DRAW_BUFFER_H_
#define FREDIT_CORE_DRAW_BUFFER_H_

// A DrawBuffer is divided into Sections. A DrawSection is divided into
// DrawLines, which themselves are comprised of DrawCells. A DrawCell displays
// several characters sharing the same properties (color, fonts etc.)
//
// ##################################################  section 0.
// |            |   |      |        |            |  |  line 0.
// --------------------------------------------------
// |   |         |         |                           line 1.
// ##################################################  section 1.
// |     |          |              |     | | | |  | |  line 0.
// --------------------------------------------------
// | | | | | |    | | |      | | |   | |           ||  line 1.
// --------------------------------------------------
// |         |                     |   | | |           line 2.
// ...

namespace fredit { namespace core {

// Forward declarations.
class Cursor;
class DrawCell;
class View;

class DrawBuffer {
 public:
  DrawBuffer(const View* view, int columns, int height);

 private:
  const View* view_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_DRAW_BUFFER_H_
