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

#include "core/buffer.h"

#include <glog/logging.h>

#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include "core/cursor.h"
#include "core/line.h"
#include "core/region.h"

namespace fredit { namespace core {

typedef QVector<Line*> BufferData;

struct Buffer::BufferInfo {
  BufferInfo() {}

  QList<View*> views;
  QString path;
  BufferData* contents;
  BufferState state;
};

Buffer::Buffer()
    : bufinfo_(new BufferInfo()) {
  VLOG(1) << "Creating new buffer.";
}

Buffer::~Buffer() {
  VLOG(1) << "Destroying buffer.";
}

void Buffer::Clear() {
  DeleteRegion(Region(Cursor(0,0), Cursor(0, GetLineCount())));
}

void Buffer::DeleteRegion(const Region& region) {
}

Cursor Buffer::InsertData(const Cursor& cursor, const QStringList& data) {
  // Cursor to store the position after data has been inserted.
  Cursor after;

  // If data is empty, return immediately.
  if (data.count() == 0)
    return after;

  // Otherwise, get the current line number, and obtain the line at that
  // position.
  int cur_line_num = cursor.line();

  Line* cur_line = GetLineAt(cur_line_num);

  // Sanity check.
  CHECK_LE(cursor.column(), cur_line->GetLength());

  // All data in the current line to the left of the cursor.
  QString left_data = cur_line->data().left(cursor.column());

  // All data in the current line to the right of the cursor.
  QString right_data = cur_line->data().mid(cursor.column());

  // Number of new lines to be inserted.
  int num_new_lines = data.count();

  // Append the first line of data at the current cursor position.
  left_data += data[0];

  // Fast-path for inserting a single line.
  if (num_new_lines == 1) {
    after.set_column(left_data.length());
    left_data += right_data;
    cur_line->set_data(left_data);
  } else { // We are inserting at least two lines.
    // Iterate through the rest of the data, inserting each line.
    for (int i = 1; i < num_new_lines - 1; ++i, ++cur_line_num) {
      bufinfo_->contents->insert(cur_line_num, new Line(data[i]));
    }

    // right_data must be appended to the last line.
    left_data = data[num_new_lines - 1];
    after.set_column(left_data.length());
    left_data += right_data;
    bufinfo_->contents->insert(++cur_line_num, new Line(left_data));
  }
  after.set_line(cur_line_num);
  return after;
}

int Buffer::GetLineCount() const {
  return bufinfo_->contents->count();
}

Line* Buffer::GetLineAt(int line_number) {
  CHECK_LE(line_number, GetLineCount()) << "Invalid line requested.";
  return bufinfo_->contents->at(line_number);
}

void Buffer::LoadFile(const QString& filename) {
  VLOG(1) << filename.toStdString();

  if (filename.isNull() || filename.isEmpty())
    return;

  QFileInfo fileinfo(filename);
  if (fileinfo.isDir()) {
    LOG(WARNING) << "Operation now allowed on directories.";
    return;
  }

  // Clear the buffer.
  Clear();

  // Set the path.
  SetPath(filename);

  // Open the file.
  QFile file(bufinfo_->path);
  if (file.exists() && file.open(QIODevice::ReadOnly)) {
    // Read in the file.
    QStringList data;
    QTextStream stream(&file);
    while (!stream.atEnd())
      data << stream.readLine();

    // Populate the buffer.
    InsertData(Cursor(0,0), data);
  }
}

void Buffer::SetPath(const QString& path) {
  bufinfo_->path = QFileInfo(path.trimmed()).absoluteFilePath();
}

void Buffer::AddView(View* view) {
  if (bufinfo_->views.contains(view)) {
    LOG(WARNING) << "Attemping to add a view that was already added.";
    return;
  }
  bufinfo_->views.append(view);
}

} } // end namespace.
