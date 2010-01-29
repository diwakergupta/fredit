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

#ifndef FREDIT_CORE_KEY_H_
#define FREDIT_CORE_KEY_H_

#include <Qt>

namespace fredit { namespace core {

class Key {
 public:
  Key();
  Key(int key, Qt::KeyboardModifiers modifiers);
  Key(const Key&);

  int key() const { return key_; }
  Qt::KeyboardModifiers modifiers() const { return modifiers_; }

 private:
  int key_;
  Qt::KeyboardModifiers modifiers_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_KEY_EVENT_H_
