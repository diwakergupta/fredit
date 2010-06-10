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

#ifndef FREDIT_CORE_DRAW_LINE_H_
#define FREDIT_CORE_DRAW_LINE_H_

#include <QList>

#include "core/draw_cell.h"

namespace fredit { namespace core {

// Forward declarations.
class Color;
class Font;

class DrawLine : public QList<DrawCell> {
 public:
  DrawLine();
  virtual ~DrawLine();

  void SetFont(const Font& font);
  void SetForegroundColor(const Color& color);
  void SetBackgroundColor(const Color& color);
  void Clear();
  void Flush();

  inline const int width() const { return width_; }
  inline const int length() const { return length_; }

 private:
  DrawCell current_cell_;
  DrawCell* working_cell_;
  int width_;
  int length_;
  bool changed_;
};

} }

#endif // end of include guard: FREDIT_CORE_DRAW_LINE_H_
