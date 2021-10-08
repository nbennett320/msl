#include <kout.h>
#include "msl.h"
#include "String.h"

// extern "C" {
//   void test() {
//     String s = "Hello world!";
//     kprintf("hello world normal 123456");

//     kprintf(s.toCharArray());
//   }
// }

int test_helper() {
  String s = "Hello world!";
  kprintf("hello world normal 123456");
  kprintf(s.toCharArray());
  return 0;
}

extern "C" {
  // hi 2
int test() {
  String s = "Hello world!";
  kprintf("hello world normal 123456");
  kprintf(s.toCharArray());
  return 0;
}
}
// 