#ifndef __LINUX_COMPILER_H
#error "Please don't include <linux/compiler-clang.h> directly, include <linux/compiler.h> instead."
#endif

/* Some compiler specific definitions are overwritten here
 * for Clang compiler
 */

#ifdef uninitialized_var
#undef uninitialized_var
#define uninitialized_var(x) x = *(&(x))
#endif

#ifdef noinline
#undef noinline
#endif

#undef inline
#define inline		__attribute__((noinline)) notrace __maybe_unused

#undef __inline__
#define __inline__	__attribute__((noinline)) notrace __maybe_unused

#undef __inline
#define __inline	__attribute__((noinline)) notrace __maybe_unused
