#include <stdio.h>

/*
The strings used in the code are defined at the top of the object code

The intergers were defined in movl

addition is defined using addl

The optimization of replaces the multiple functions with the
output of the functions in order to make the code run faster.
*/

int main() {
    int x=5;
    int y =x+1;
    printf("%i",y);
    return 0;
}
