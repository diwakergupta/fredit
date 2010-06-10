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

#ifndef FREDIT_CORE_DRAW_CELL_
#define FREDIT_CORE_DRAW_CELL_

#include <QList>
#include <QString>

#include "core/color.h"
#include "core/font.h"
#include "core/fredit.h"

namespace fredit { namespace core {

class DrawCell {
 public:
  DrawCell();
  DrawCell(const DrawCell& cell);
  virtual ~DrawCell();

  // void AddSelection(SelectionType type);
  // void DelSelection(SelectionType type);

  inline const Color foreground_color() const {
    return foreground_color_;
  }
  inline void set_foreground_color(const Color& color) {
    foreground_color_ = color;
  }

  inline const Color background_color() const {
    return background_color_;
  }
  inline void set_background_color(const Color& color) {
    background_color_ = color;
  }

  inline const Font font() const {
    return font_;
  }
  inline void set_font(const Font& font) {
    font_ = font;
  }

  void Clear();

  // int Step(const QString& data);

  // DrawCell SplitLeft(int column) const;
  // DrawCell SplitMid(int column) const;
  // DrawCell LeftSteps(int steps) const;
  // DrawCell MidSteps(int steps) const;

 private:
  // int selections_;
  Color foreground_color_;
  Color background_color_;
  Font font_;
  // QString content_;
  // QList<int> steps_;
  // int steps_shift_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_DRAW_CELL_
