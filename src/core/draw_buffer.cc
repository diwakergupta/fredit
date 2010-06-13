// Fredit: A fresh editor.
// Copyright (c) 2010 Diwaker Gupta <diwaker@floatingsun.net>

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

#include "core/draw_buffer.h"

#include "glog/logging.h"

#include "core/draw_line.h"
#include "core/region.h"
#include "core/view.h"

namespace fredit { namespace core {

DrawBuffer::DrawBuffer(const View* view, int columns, int height)
    : view_(view),
      first_buffer_line_(0) {
  content_.append(DrawSection() << DrawLine());
}

void DrawBuffer::SetScreenSize(int columns, int lines) {
  CHECK_GT(screen_width_, 0);
  CHECK_GT(screen_height_, 0);
  screen_width_ = columns;
  screen_height_ = lines;
}

int DrawBuffer::GetLastBufferLine() const {
  return first_buffer_line_ + content_.count() - 1;
}

int DrawBuffer::GetCurrentHeight() const {
  int height = 0;
  for (int i = screen_top_buffer_line_;
       height < screen_height_ && i <= GetLastBufferLine();
       ++i) {
    height += content_[i - first_buffer_line_].count();
  }
  return height;
}

Region DrawBuffer::SetDrawSectionForLine(int buffer_line,
                                         DrawSection section) {
  int line_index = buffer_line - first_buffer_line_;
  CHECK_GE(line_index, 0);
  CHECK_LE(line_index, content_.count());

  Region affected;

  int delta = 0;
  if (line_index == content_.count()) {
    content_ << section;
  } else {
    delta = section.count() - content_[line_index].count();
    content_.replace(line_index, section);
  }

  if (buffer_line >= screen_top_buffer_line_) {
  }

  return affected;
}

} }
