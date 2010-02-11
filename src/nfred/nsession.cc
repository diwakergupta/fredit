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

#include "nfred/nsession.h"

#include "core/buffer.h"

namespace fredit { namespace nfred {

void NSession::CreateInstance() {
  static NSession instance;
  SetInstance(&instance);
}

NSession::NSession() : core::Session() {
}

NSession::~NSession() {
}

void NSession::GuiPopupMessage(const QString& msg) {
}

void NSession::GuiQuit(int error_code) {
}

core::View* NSession::GuiCreateView(core::Buffer* buf) {
}

void NSession::GuiChangeView(core::View* view) {
}

void NSession::GuiDeleteView(core::View* view) {
}

void NSession::GuiCreateBuffer(core::Buffer* buf) {
}

void NSession::GuiRemoveBuffer(core::Buffer* buf) {
}

} } // end namespace.
