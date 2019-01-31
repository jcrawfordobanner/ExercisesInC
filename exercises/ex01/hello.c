#include <stdio.h>

int add(int x, int y) {
  return x+y;
}

int main() {
    printf("Hello, World!\n");
    add(2,4);
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("c is %d\n", c);
    return 0;
}
