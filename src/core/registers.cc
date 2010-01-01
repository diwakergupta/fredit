// Fredit: A fresh editor.

// Copyright (C) 2009 Diwaker Gupta <diwaker@floatingsun.net>

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

#include "registers.h"

#include <glog/logging.h>

namespace fred { namespace core {

void Registers::SetRegister(QChar reg_chr, const QStringList& value) {
  registers_[reg_chr] = value;
  DLOG(INFO) << "Setting register[" << reg_chr.toAscii() << "] = "
             << value.join(", ").toStdString();
}

QStringList& Registers::GetRegister(QChar reg_chr) {
  return registers_[reg_chr];
}

} } // end namespace.
