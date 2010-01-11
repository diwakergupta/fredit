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

#include <basedir.h>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include <QCoreApplication>
#include <QDir>
#include <QString>

#include "core/buffer.h"
#include "core/fredit.h"
#include "nfred/nsession.h"

namespace nfred = fredit::nfred;
namespace core = fredit::core;

DECLARE_string(log_dir);

int main(int argc, char** argv) {
  google::AllowCommandLineReparsing();
  google::ParseCommandLineFlags(&argc, &argv, true);

  // Initialize the XDG handle.
  // TODO: XDG is not a cross-platform standard.
  xdgHandle handle;
  xdgInitHandle(&handle);

  // TODO: this should move out into a common function (or possibly into core).
  // Setup our data, log and config directories.
  QDir xdg_data_dir(QString(xdgDataHome(&handle)));
  CHECK(xdg_data_dir.exists());
  if (!xdg_data_dir.exists(core::Constants::kAppName))
    CHECK(xdg_data_dir.mkdir(core::Constants::kAppName));

  QDir fredit_dir(QString("%1/%2").arg(xdg_data_dir.absolutePath(),
                                       core::Constants::kAppName));
  if (!fredit_dir.exists("logs"))
    CHECK(fredit_dir.mkdir("logs"));

  QDir xdg_config_dir(QString(xdgConfigHome(&handle)));
  CHECK(xdg_config_dir.exists());
  if (!xdg_config_dir.exists(core::Constants::kAppName))
    CHECK(xdg_config_dir.mkdir(core::Constants::kAppName));

  FLAGS_log_dir = fredit_dir.absoluteFilePath("logs").toStdString();
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Starting nfred.";

  QCoreApplication* app = new QCoreApplication(argc, argv);
  app->setOrganizationName("fred");
  app->setOrganizationDomain("fredit.org");
  app->setApplicationName("nfred");

  nfred::NSession::CreateInstance();

  // QTimer::singleShot(0, 
    // static_cast<nfred::NSession*>(core::Session::GetInstance()),
    // SLOT(FrontendGuiReady()));

  return app->exec();
}
