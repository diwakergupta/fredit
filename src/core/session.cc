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

#include "core/session.h"

#include <basedir.h>
#include <glog/logging.h>

#include <core/fredit.h>

namespace fredit { namespace core {

SessionInterface::~SessionInterface() {
}

Session* Session::instance_ = NULL;

void Session::Init() {
  InitResources();
}

void Session::InitResources() {
  // Initialize the XDG handle.
  // TODO: XDG is not a cross-platform standard.
  xdgHandle handle;
  xdgInitHandle(&handle);

  // Setup our data, log and config directories.
  QDir xdg_data_dir(QString(xdgDataHome(&handle)));
  CHECK(xdg_data_dir.exists());
  if (!xdg_data_dir.exists(Constants::kAppName))
    CHECK(xdg_data_dir.mkdir(Constants::kAppName));

  datadir_ = new QDir(QString("%1/%2").arg(xdg_data_dir.absolutePath(),
                                           Constants::kAppName));
  if (!datadir_->exists("logs"))
    CHECK(datadir_->mkdir("logs"));

  QDir xdg_config_dir(QString(xdgConfigHome(&handle)));
  CHECK(xdg_config_dir.exists());
  if (!xdg_config_dir.exists(Constants::kAppName))
    CHECK(xdg_config_dir.mkdir(Constants::kAppName));
  confdir_ = new QDir(QString("%1/%2").arg(xdg_config_dir.absolutePath(),
                                          Constants::kAppName));
}

Session::Session()
  : datadir_(NULL), confdir_(NULL) {
  Init();
}

Session::~Session() {
}

Session* Session::GetInstance() {
  if (!instance_) {
    LOG(ERROR) << "GetInstance has not been called.";
  }
  return instance_;
}

void Session::SetInstance(Session* instance) {
  instance_ = instance;
}

} } // end namespace.
