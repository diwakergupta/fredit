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

#include "core/font.h"

namespace fredit { namespace core {

bool Font::IsBold() const {
  return weight_ > Normal;
}

bool Font::operator==(const Font& right) const {
  return (weight_ == right.weight_ && italic_ == right.italic_ &&
          underline_ == right.underline_ && overline_ == right.overline_ &&
          strikeout_ == right.strikeout_);
}

bool Font::operator!=(const Font& right) const {
  return !(*this == right);
}

Font& Font::operator=(const Font& right) {
  weight_ = right.weight_;
  italic_ = right.italic_;
  underline_ = right.underline_;
  overline_ = right.overline_;
  strikeout_ = right.strikeout_;
  return *this;
}

} } // end namespace.
