#include <stdio.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

int foo = 7;
int bar = 4;

static char * test_foo() {
  char* b =icmpcode_v4(0);
   mu_assert("network unreachable", b);
   return 0;
}

static char * all_tests() {
   mu_run_test(test_foo);
   return 0;
}

int main(int argc, char **argv) {
   char *result = all_tests();
   if (result != 0) {
       printf("%s\n", result);
   }
   else {
       printf("ALL TESTS PASSED\n");
   }
   printf("Tests run: %d\n", tests_run);

   return result != 0;
}
