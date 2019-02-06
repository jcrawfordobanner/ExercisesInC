/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

//#5
void address(int k){
  printf("Address is %p\n",&k);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    //#4
    void *l = malloc(128);

    //5
    int n;

    //#6
    void *y = malloc(16);
    void *x = malloc(16);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    //#4
    printf ("l points to %p\n", l);

    //#5
    address(n);

    //#6
    printf ("y points to %p\n", y);
    printf ("x points to %p\n", x);
    printf("The difference is %lo\n",x-y);
    //The difference is 64

    return 0;
}
