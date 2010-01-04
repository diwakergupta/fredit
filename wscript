# Fredit: A fresh editor.
#
# Copyright (C) 2009 Diwaker Gupta <diwaker@floatingsun.net>

# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51 Franklin
# Street, Fifth Floor, Boston, MA 02110-1301, USA.

srcdir = "."
blddir = "build"

def set_options(opt):
  opt.sub_options("src")

def configure(conf):
  conf.sub_config("src")

def build(bld):
  bld.add_subdirs("src")
