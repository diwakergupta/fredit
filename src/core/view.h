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

#ifndef FRED_CORE_VIEW_H_
#define FRED_CORE_VIEW_H_

#include "view-interface.h"

namespace fred { namespace core {

// Forward declarations.
class Buffer;
class Session;

// A View encapsulates the on-screen representation of a Buffer. A Buffer may
// belong to multiple Views, but a View may only contain a single Buffer. A View
// is associated with a Session as well.
class View : public ViewInterface {
 public:
  View(Buffer*, Session*);
  virtual ~View();

 private:
  Session* session_;
  Buffer* buffer_;
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_VIEW_H_
