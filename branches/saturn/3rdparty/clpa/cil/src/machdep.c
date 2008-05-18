/*
 *
 * Copyright (c) 2001-2002, 
 *  George C. Necula    <necula@cs.berkeley.edu>
 *  Scott McPeak        <smcpeak@cs.berkeley.edu>
 *  Wes Weimer          <weimer@cs.berkeley.edu>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. The names of the contributors may not be used to endorse or promote
 * products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "../config.h"

#include <stdio.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_WCHAR_H
#include <wchar.h>
#endif

#ifdef _GNUCC
#define LONGLONG long long
#define CONST_STRING_LITERALS "true"
#define VERSION __VERSION__
#define VERSION_MAJOR __GNUC__
#define VERSION_MINOR __GNUC_MINOR__
#endif

#ifdef _MSVC
#define LONGLONG __int64
#define CONST_STRING_LITERALS "false"
#define VERSION "Microsoft C"
#define VERSION_MAJOR (_MSC_VER / 100)
#define VERSION_MINOR (_MSC_VER % 100)
#endif

/* The type for the machine dependency structure is generated from the
   Makefile */
int main() {
  fprintf(stderr, "Generating machine dependency information for CIL\n");

  printf("(* Generated by code in %s *)\n", __FILE__);
  printf("\t version_major    = %d;\n", VERSION_MAJOR);
  printf("\t version_minor    = %d;\n", VERSION_MINOR);
  printf("\t version          = \"%s\";\n", VERSION);
  // Size of certain types
  printf("\t sizeof_short     = %d;\n", sizeof(short));
  printf("\t sizeof_int       = %d;\n", sizeof(int));
  printf("\t sizeof_long      = %d;\n", sizeof(long));
  printf("\t sizeof_longlong  = %d;\n", sizeof(LONGLONG));
  printf("\t sizeof_ptr       = %d;\n", sizeof(int *));
  printf("\t sizeof_enum      = %d;\n", sizeof(enum e { ONE, TWO }));
  printf("\t sizeof_float     = %d;\n", sizeof(float));
  printf("\t sizeof_double    = %d;\n", sizeof(double));
  printf("\t sizeof_longdouble  = %d;\n", sizeof(long double));
  printf("\t sizeof_void      = %d;\n", sizeof(void));
  printf("\t sizeof_fun       = %d;\n",
#ifdef __GNUC__
         sizeof(main)
#else
         0
#endif
           );

  // definition of size_t
  {
    printf("\t size_t = \"%s\";\n", TYPE_SIZE_T);
    printf("\t wchar_t = \"%s\";\n", TYPE_WCHAR_T);
  }

  // The alignment of a short
  {
    struct shortstruct {
      char c;
      short s;
    };
    printf("\t alignof_short = %d;\n",
           (int)(&((struct shortstruct*)0)->s));
  }

  // The alignment of an int
  {
    struct intstruct {
      char c;
      int i;
    };
    printf("\t alignof_int = %d;\n",
           (int)(&((struct intstruct*)0)->i));
  }
  
  // The alignment of a long
  {
    struct longstruct {
      char c;
      long l;
    };
    printf("\t alignof_long = %d;\n",
           (int)(&((struct longstruct*)0)->l));
  }

  // The alignment of long long
  {
    struct longlong {
      char c;
      LONGLONG ll;
    };
    printf("\t alignof_longlong = %d;\n",
           (int)(&((struct longlong*)0)->ll));
  }

  // The alignment of a ptr
  {
    struct ptrstruct {
      char c; 
      int * p;
    };
    printf("\t alignof_ptr = %d;\n",
           (int)(&((struct ptrstruct*)0)->p));
  }

  // The alignment of an enum
  {
    struct enumstruct {
      char c; 
      enum e2 { THREE, FOUR, FIVE } e;
    };
    printf("\t alignof_enum = %d;\n",
           (int)(&((struct enumstruct*)0)->e));
  }

  // The alignment of a float
  {
    struct floatstruct {
      char c;
      float f;
    };
    printf("\t alignof_float = %d;\n",
           (int)(&((struct floatstruct*)0)->f));
  }
  
  // The alignment of double
  {
    struct s1 {
      char c;
      double d;
    };
    printf("\t alignof_double = %d;\n",
           (int)(&((struct s1*)0)->d));
  }    

  // The alignment of long  double
  {
    struct s1 {
      char c;
      long double ld;
    };
    printf("\t alignof_longdouble = %d;\n",
           (int)(&((struct s1*)0)->ld));
  }    

  printf("\t alignof_str = %d;\n",
#ifdef __GNUC__
         __alignof("a string")
#else
         0
#endif
         );

  printf("\t alignof_fun = %d;\n",
#ifdef __GNUC__
         __alignof(main)
#else
         0
#endif
         );

  // Whether char is unsigned
  printf("\t char_is_unsigned = %s;\n", 
         ((char)0xff) > 0 ? "true" : "false");


  // Whether string literals contain constant characters
  puts("\t const_string_literals = " CONST_STRING_LITERALS ";");


  // endianity
  {
    int e = 0x11223344;
    printf("\t little_endian = %s;\n",
           (0x44 == *(char*)&e) ? "true" :
           ((0x11 == *(char*)&e) ? "false" : (exit(1), "false")));
  }

  exit(0);
} 