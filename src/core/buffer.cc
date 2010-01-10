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

#include "buffer.h"

#include <glog/logging.h>

namespace fred { namespace core {

Buffer::Buffer()
    : buf_info_(new BufferInfo()) {
  VLOG(1) << "Creating new buffer.";
}

Buffer::~Buffer() {
  VLOG(1) << "Destroying buffer.";
}

void Buffer::LoadFile(const QString& filename) {
  VLOG(1) << filename.toStdString();
}

void Buffer::AddView(View* view) {
  if (buf_info_->views.contains(view)) {
    LOG(WARNING) << "Attemping to add a view that was already added.";
    return;
  }
  buf_info_->views.append(view);
}

} } // end namespace.
