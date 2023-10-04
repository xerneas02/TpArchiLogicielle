#ifndef betterCPP__core__keyword
#define betterCPP__core__keyword
#include "__base__.hpp"

#define null nullptr

//#define false 0
//#define true  (!false)
//typedef int8_t bool;

typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;

typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;


typedef int8_t    int8;
typedef int16_t   int16;
typedef int32_t   int32;
typedef int64_t   int64;


typedef uint8_t   uint8;
typedef uint16_t  uint16;
typedef uint32_t  uint32;
typedef uint64_t  uint64;


typedef intptr_t  nint; // aka int in extenC
typedef intptr_t  isize;
typedef intptr_t  iptr;
typedef uintmax_t imax;
#define isize_error (INTPTR_MIN)

typedef uintptr_t nuint; // aka uint in extenC
typedef uintptr_t usize;
typedef uintptr_t uptr;
typedef intmax_t  umax;
#define usize_error (UINTPTR_MAX)

typedef uintptr_t uptr;
typedef uint8_t byte;

typedef uint8  char8;
typedef uint16 char16;
typedef uint32 char32;
typedef uint64 char64;

//typedef FILE file;

typedef float  float32;
typedef double float64;

typedef float  f32;
typedef double f64;
#define fmax double

#define f32_format  "f"
#define f64_format  "lf"
#define fmax_format f64_format
//typedef double fmax;


// max :
#define i8_max  INT8_MAX
#define i16_max INT16_MAX
#define i32_max INT32_MAX
#define i64_max INT64_MAX

#define u8_max  UINT8_MAX
#define u16_max UINT16_MAX
#define u32_max UINT32_MAX
#define u64_max UINT64_MAX

#define nint_max  INTPTR_MAX
#define isize_max INTPTR_MAX
#define iptr_max  INTPTR_MAX
#define imax_max  INTMAX_MAX


#define nuint_max UINTPTR_MAX
#define usize_max UINTPTR_MAX
#define uptr_max  UINTPTR_MAX
#define umax_max  UINTMAX_MAX

// min :
#define i8_min  INT8_MIN
#define i16_min INT16_MIN
#define i32_min INT32_MIN
#define i64_min INT64_MIN

#define u8_min  UINT8_MIN
#define u16_min UINT16_MIN
#define u32_min UINT32_MIN
#define u64_min UINT64_MIN

#define nint_min  INTPTR_MIN
#define isize_min INTPTR_MIN
#define iptr_min  INTPTR_MIN
#define imax_min  INTMAX_MIN

#define nuint_min UINTPTR_MIN
#define usize_min UINTPTR_MIN
#define uptr_min  UINTPTR_MIN
#define umax_min  UINTMAX_MIN


// format :
#define i8_format  PRIi8
#define i16_format PRIi16
#define i32_format PRIi32
#define i64_format PRIi64

#define u8_format  PRIu8
#define u16_format PRIu16
#define u32_format PRIu32
#define u64_format PRIu64

#define nint_format  PRIiPTR
#define isize_format PRIiPTR
#define iptr_format  PRIiPTR
#define imax_format  PRIiPTR

#define nuint_format PRIuPTR
#define usize_format PRIuPTR
#define uptr_format  PRIuPTR
#define umax_format  PRIuPTR




// text & IO :
typedef uint32 rune; // aka char in extenC
#define c_string char*

#define char_eof     ((char)'\0')
#define rune_eof     ((rune)(char_eof))

typedef FILE c_file;
typedef FILE file;

typedef intmax_t  ifpos;
#define ifpos_max     INTMAX_MAX
#define ifpos_min     INTMAX_MIN

typedef uintmax_t ufpos;
#define ufpos_max     UINTMAX_MAX
#define ufpos_min     UINTMAX_MIN

#endif