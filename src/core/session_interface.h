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

#ifndef FREDIT_CORE_SESSION_INTERFACE_H_
#define FREDIT_CORE_SESSION_INTERFACE_H_

#include <QString>

// This class declares the interface that each GUI front-end must implement. The
// fredit core will use these methods as callbacks into the GUI.

namespace fredit { namespace core {

class Buffer;
class View;

class SessionInterface {
 public:
  virtual void GuiPopupMessage(const QString& msg) = 0;

  virtual void GuiQuit(int error_code) = 0;

  virtual View* GuiCreateView(Buffer* buf) = 0;
  virtual void GuiChangeView(View* view) = 0;
  virtual void GuiDeleteView(View* view) = 0;
  virtual void GuiCreateBuffer(Buffer* buf) = 0;
  virtual void GuiRemoveBuffer(Buffer* buf) = 0;

  virtual ~SessionInterface();
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_SESSION_INTERFACE_H_
