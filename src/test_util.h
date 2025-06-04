/*
 * s3fs - FUSE-based file system backed by Tencentyun COS
 *
 * Copyright 2007-2008 Randy Rizun <rrizun@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <cstdlib>
#include <iostream>

template <typename T> void assert_nonil(const T *x, const char *file, int line)
{
    if (x == NULL) {
        std::cerr << "NULL at " << file << ":" << line << std::endl;
        std::exit(1);
    }
}
template <typename T> void assert_equals(const T &x, const T &y, const char *file, int line)
{
  if (x != y) {
    std::cerr << x << " != " << y << " at " << file << ":" << line << std::endl;
    std::exit(1);
  }
}
template <typename T> void assert_not_equals(const T &x, const T &y, const char *file, int line)
{
  if (x == y) {
    std::cerr << x << " == " << y << " at " << file << ":" << line << std::endl;
    std::exit(1);
  }
}

void assert_strequals(const char *x, const char *y, const char *file, int line)
{
  if(x == NULL && y == NULL){
    return;
  } else if((x == NULL || y == NULL) || strcmp(x, y) != 0){
    std::cerr << x << " != " << y << " at " << file << ":" << line << std::endl;
    std::exit(1);
  }
}

#define ASSERT_NONIL(x) \
  assert_nonil((x), __FILE__, __LINE__)

#define ASSERT_EQUALS(x, y) \
  assert_equals((x), (y), __FILE__, __LINE__)

#define ASSERT_NOTEQUALS(x, y) \
  assert_not_equals((x), (y), __FILE__, __LINE__)

#define ASSERT_STREQUALS(x, y) \
  assert_strequals((x), (y), __FILE__, __LINE__)
