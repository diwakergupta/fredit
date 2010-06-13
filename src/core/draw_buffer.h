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

#include <QList>

#include "core/cursor.h"
#include "core/draw_cell.h"

namespace fredit { namespace core {

// Forward declarations.
class DrawLine;
class Region;
class View;

typedef QList<DrawLine> DrawSection;

class DrawBuffer {
 public:
  DrawBuffer(const View* view, int columns, int height);

  // Returns the buffer line number corresponding to the screen top line.
  int ScreenTopBufferLine() const;

  int ScreenBottomBufferLine() const;

  void SetScreenSize(int columns, int lines);

  inline int screen_height() const { return screen_height_; }
  inline int screen_width() const { return screen_width_; }
  inline int first_buffer_line() const { return first_buffer_line_; }

  inline const QList<DrawSection> content() { return content_; }

  // Return the index of the last in-memory line in the buffer.
  int GetLastBufferLine() const;

  // Compute current height used by lines on screen.
  int GetCurrentHeight() const;

  // Sets the draw sections corresponding to the buffer line buffer_line.
  // Returns the part of the buffer affected by the change.
  // TODO(diwaker): Change to pass in Region by ref, instead of returning it.
  Region SetDrawSectionForLine(int buffer_line, DrawSection section);

  // Remove the specified line from the buffer.
  // Return the region affected by the change.
  // TODO(diwaker): Use output params.
  Region DeleteLine(int buffer_line);

 private:
  QList<DrawSection> content_;
  // QList<DrawLineLock> locks_;
  Cursor screen_offset_;
  DrawCell eol_cell_;

  int screen_width_;
  int screen_height_;
  int first_buffer_line_;
  int screen_top_buffer_line_;

  const View* view_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_DRAW_BUFFER_H_
