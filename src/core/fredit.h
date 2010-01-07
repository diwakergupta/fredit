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

#ifndef FRED_CORE_FREDIT_H_
#define FRED_CORE_FREDIT_H_

// Main include file for Fredit core.

namespace fredit { namespace core {

enum OptionScope {
  Default,
  Global,
  Local
};

enum OptionContext {
  None,
  Session,
  Buffer,
  View
};

enum OptionType {
  Invalid,
  Int,
  String,
  List,
  Bool,
  Map,
  Color
};

enum MappingMode {
  Normal,
  CmdLine,
  Visual,
  PendingOp,
  Insert,
};

enum SelectionType {
  Any,
  Search,
  Visual
};

enum IntervalType {
  Buffer,
  Screen
};

enum ClipboardMode {
  Clipboard,
  Selection
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_FREDIT_H_
