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

#include "core/color.h"

namespace fredit { namespace core {

Color::Color()
    : isvalid_(false) {
}

Color::Color(int red, int green, int blue)
    : red_(red), green_(green), blue_(blue), isvalid_(true) {
}

bool Color::Equals(const Color& other) const {
  return (isvalid_ == other.isvalid_ &&
          red_ == other.red_ &&
          green_ == other.green_ &&
          blue_ == other.blue_);
}

} } // end namespace.
