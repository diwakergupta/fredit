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

#ifndef FRED_NFRED_NSESSION_H_
#define FRED_NFRED_NSESSION_H_

#include "core/macros.h"
#include "core/session.h"
#include "nfred/nview.h"

namespace fred { namespace nfred {

class NSession : public core::Session {
 public:
  static void CreateInstance();

 private:
  NSession();
  virtual ~NSession();
  DISALLOW_COPY_AND_ASSIGN(NSession);
};

} } // end namespace.

#endif // end of include guard: FRED_NFRED_NSESSION_H_