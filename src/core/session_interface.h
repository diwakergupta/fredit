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

#ifndef FRED_CORE_SESSION_INTERFACE_H_
#define FRED_CORE_SESSION_INTERFACE_H_

// This class declares the interface that each GUI front-end must implement. The
// fredit core will use these methods as callbacks into the GUI.

namespace fredit { namespace core {

class SessionInterface {
 public:
  virtual ~SessionInterface() {}
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_SESSION_INTERFACE_H_
