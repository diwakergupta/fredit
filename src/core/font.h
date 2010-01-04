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

#ifndef FRED_CORE_FONT_H_
#define FRED_CORE_FONT_H_

namespace fred { namespace core {

class Font {
 public:
  enum Weight {
    Light,
    Normal,
    DemiBold,
    Bold
  };

  Font() {}

  Weight weight() const { return weight_; }
  void set_weight(Weight weight) { weight_ = weight; }

  bool italic() const { return italic_; }
  void set_italic(bool italic) { italic_ = italic; }

  bool underline() const { return underline_; }
  void set_underline(bool underline) { underline_ = underline; }

  bool overline() const { return overline_; }
  void set_overline(bool overline) { overline_ = overline; }

  bool strikeout() const { return strikeout_; }
  void set_strikeout(bool strikeout) { strikeout_ = strikeout; }

  bool IsBold() const;

  bool operator!=(const Font& right) const;
  bool operator==(const Font& right) const;

  Font& operator=(const Font& right);

 private:
  Weight weight_;
  bool italic_;
  bool underline_;
  bool overline_;
  bool strikeout_;
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_FONT_H_
