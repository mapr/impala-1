// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef UTIL_UBSAN_H_
#define UTIL_UBSAN_H_

// Utilities mimicking parts of the standard prone to accidentally using in a way causeing
// undefined behavior.

#include <cstring>

#include "common/logging.h"

class Ubsan {
 public:
  static void* MemSet(void* s, int c, size_t n) {
    if (s == nullptr) {
      DCHECK_EQ(n, 0);
      return s;
    }
    return std::memset(s, c, n);
  }
  static void* MemCpy(void* dest, const void* src, size_t n) {
    if (dest == nullptr || src == nullptr) {
      DCHECK_EQ(n, 0);
      return dest;
    }
    return std::memcpy(dest, src, n);
  }
  static int MemCmp(const void *s1, const void *s2, size_t n) {
    if (s1 == nullptr || s2 == nullptr) {
      DCHECK_EQ(n, 0);
      return 0;
    }
    return std::memcmp(s1, s2, n);
  }
};

#endif // UTIL_UBSAN_H_
