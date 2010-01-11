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

#ifndef FRED_CORE_BUFFER_H_
#define FRED_CORE_BUFFER_H_

#include <QList>
#include <QString>

namespace fredit { namespace core {

// Forward declarations.
class View;

// A Buffer is an in-memory representation of the contents of a file. Note that
// the Buffer is only responsible for the content, and not the presentation --
// that is the responsibility of a View. A Buffer can belong to multiple Views.
//
// Every Buffer _must_ be registered with a Session.

class Buffer {
 public:
  Buffer();
  virtual ~Buffer();

  // ===========================================================================
  void LoadFile(const QString& filename);

  // ===========================================================================
  void AddView(View* view);

  // ===========================================================================
  enum BufferState {
    BufferActive,
    BufferHidden,
    BufferInactive
  };

 private:
  struct BufferInfo {
    BufferInfo() {}
    QList<View*> views;
  };
  BufferInfo* buf_info_;
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_BUFFER_H_
