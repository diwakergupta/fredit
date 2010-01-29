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

#ifndef FREDIT_CORE_BUFFER_H_
#define FREDIT_CORE_BUFFER_H_

#include <QList>
#include <QString>
#include <QStringList>
#include <QVector>

namespace fredit { namespace core {

// Forward declarations.
class Cursor;
class Line;
class View;
class Region;

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
  // Content operations.
  // ===========================================================================
  Cursor InsertData(const Cursor& cursor, const QStringList& data);
  void DeleteRegion(const Region& region);
  void Clear();

  // ===========================================================================
  void LoadFile(const QString& filename);
  void SetPath(const QString& path);

  // ===========================================================================
  void AddView(View* view);

  int GetLineCount() const;
  Line* GetLineAt(int line_number);

  // ===========================================================================
  enum BufferState {
    BufferActive,
    BufferHidden,
    BufferInactive
  };

 private:
  // Forward declaration.
  struct BufferInfo;

  BufferInfo* bufinfo_;
};

} } // end namespace.

#endif // end of include guard: FREDIT_CORE_BUFFER_H_
