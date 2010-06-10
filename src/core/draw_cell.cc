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

#include "core/draw_cell.h"

namespace fredit { namespace core {

DrawCell::DrawCell()
    : foreground_color_(),
      background_color_(),
      font_() {
}

DrawCell::DrawCell(const DrawCell& cell)
    : foreground_color_(cell.foreground_color()),
      background_color_(cell.background_color()),
      font_(cell.font()) {
}

DrawCell::~DrawCell() {
}

void DrawCell::Clear() {
  foreground_color_ = Color();
  background_color_ = Color();
  font_ = Font();
}

} } // end namespace.
