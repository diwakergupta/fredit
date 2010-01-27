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

#include "core/session_interface.h"

#include <QList>

#include "core/macros.h"

namespace fredit { namespace core {

// Forward declarations.
class Buffer;
class Cursor;
class View;
class ViewCursor;

typedef QList<Buffer*> BufferList;
typedef QList<View*> ViewList;

class Session : public SessionInterface {
 public:
  static Session* GetInstance();
  View* CreateBufferAndView(const QString& path);

  // We assume that all the command line flags have already been parsed (either
  // by gflags or QApplication etc).
  void ParseCommandLineArgs();
  void RemoveBuffer(Buffer* buf);
  void DeleteBuffer(Buffer* buf);

  const BufferList& buffers() const { return buffers_; }
  Buffer* FindBuffer(const QString& path);
  View* CreateView(Buffer* buf);
  void DeleteView(View* view);
  View* current_view() { return current_view_; }
  void set_current_view(View* view);

 protected:
  Session();
  virtual ~Session();

  static void SetInstance(Session* instance);

  // Initialize the session.
  void Init();

  // TODO: move the log/config dir creation here.
  void InitResources();

 private:
  static Session* instance_;

  View* current_view_;
  Buffer* current_buffer_;
  BufferList buffers_;
  ViewList views_;

  DISALLOW_COPY_AND_ASSIGN(Session);
};

} } // end namespace.

#endif // end of include guard: FRED_CORE_SESSION_H_
