Written in C by Alexander Starr.

Compiled with gcc:
Apple LLVM version 5.0 (clang-500.2.79) (based on LLVM 3.3svn)
Target: x86_64-apple-darwin13.0.0
Thread model: posix

Notes:
- P1.c can calculate any number of Fibonacci numbers, as long as they fit in a C int.  The number of Fibonacci numbers printed can be adjust by changing the argument passed to fib() on line 18.
- P3.c does not use dynamically allocated memory to store the lines read from the files.  By default, it can handle 160 characters/line.  This can be adjusted by changing the preprocessor definition of LINE_LEN on line 5.
- P4.c does not produce any output when run.  It is assumed that it will be included as a header file in a test script written by the graders.