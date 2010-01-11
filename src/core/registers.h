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

#ifndef FRED_CORE_REGISTERS_H_
#define FRED_CORE_REGISTERS_H_

#include <QStringList>
#include <QMap>

namespace fredit { namespace core {

class Registers {
 public:
  // Default constructor.
  Registers() { };

  // Set the contents of register reg_chr to value.
  void SetRegister(QChar reg_chr, const QStringList& value);

  // Retrieve the contents of register reg_chr.
  QStringList& GetRegister(QChar reg_chr);

  // Return the list of all registers.
  QList<QChar> ListKeys() const {
    return registers_.keys();
  }

  // Return the list of all values.
  QList<QStringList> ListValues() const {
    return registers_.values();
  }

 private:
  QMap<QChar, QStringList> registers_;
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_REGISTERS_H_
