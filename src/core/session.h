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

#ifndef FRED_CORE_SESSION_H_
#define FRED_CORE_SESSION_H_

#include "session-interface.h"

#include <QList>

#include "macros.h"

namespace fred { namespace core {

// Forward declarations.
class Buffer;
class View;

typedef QList<Buffer*> BufferList;
typedef QList<View*> ViewList;

class Session : public SessionInterface {
 public:
  static Session* GetInstance();
  View* CreateBufferAndView();
  View* CreateView(Buffer* buffer);

 protected:
  Session();
  virtual ~Session();

  static void SetInstance(Session* instance);

 private:
  static Session* instance_;

  DISALLOW_COPY_AND_ASSIGN(Session);
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_SESSION_H_
