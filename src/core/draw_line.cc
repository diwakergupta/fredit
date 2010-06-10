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

#include "draw_line.h"

namespace fredit { namespace core {

DrawLine::DrawLine() : QList<DrawCell>() {
  Clear();
}

DrawLine::~DrawLine() {
}

void DrawLine::Clear() {
  QList<DrawCell>::clear();
  current_cell_.Clear();
  working_cell_ = NULL;
  width_ = 0;
  changed_ = true;
}

void DrawLine::SetFont(const Font& font) {
  current_cell_.set_font(font);
}

void DrawLine::SetForegroundColor(const Color& color) {
  if (!current_cell_.foreground_color().Equals(color)) {
    current_cell_.set_foreground_color(color);
    changed_ = true;
  }
}

void DrawLine::SetBackgroundColor(const Color& color) {
  if (!current_cell_.background_color().Equals(color)) {
    current_cell_.set_background_color(color);
    changed_ = true;
  }
}

void DrawLine::Flush() {
}

} } // end namespace.
