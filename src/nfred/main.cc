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

#include <iostream>

#include <cwidget/toplevel.h>
#include <cwidget/widgets/minibuf_win.h>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include <QDir>
#include <QString>

#include "core/buffer.h"
#include "core/fredit.h"
#include "nfred/nsession.h"

namespace core = fredit::core;
namespace cw = cwidget;
namespace nfred = fredit::nfred;

DECLARE_string(log_dir);

int main(int argc, char** argv) {
  // Allow other objects (such as QCoreApplication to reparse the command line).
  // This is useful if the applicatione uses flags that are not known to
  // gflags.
  google::AllowCommandLineReparsing();

  // Remove flags that are known to gflags.
  bool remove_flags = true;
  google::ParseCommandLineFlags(&argc, &argv, remove_flags);

  cw::toplevel::init();

  // Create the session.
  nfred::NSession::CreateInstance();

  // Initialize logging.
  core::Session* session = nfred::NSession::GetInstance();
  FLAGS_log_dir = session->datadir().absoluteFilePath("logs").toStdString();
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Starting nfred.";

  try {
    cw::toplevel::mainloop();
  } catch (...) {
    cw::toplevel::shutdown();
    return 0;
  }

  cw::toplevel::shutdown();
  return 0;
}
