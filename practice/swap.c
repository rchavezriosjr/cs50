#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("Value of x is: %i\n", x);
    printf("Value of y is: %i\n", y);
    printf("The address of x is: %p\n", &x);
    printf("the address of y is: %p\n", &y);
    printf("CALL SWAP(int *a, int *b), pass in &x and &y...\n");
    swap(&x, &y);
    printf("swapped!\n");
    printf("Value of x after swap is: %i\n", x);
    printf("Value of y after swap is: %i\n", y);

    
    
}

void swap(int *a, int *b)
{
    int y;
    // move this line around to see garbage value stored at address of y
    a = &y;
    
    printf("(a): a is a pointer with the address of: %p\n", a);
    printf("(*a): go to address in a, returns value:  %d\n", *a);
    printf("(b): b is a pointer with the address of: %p\n", b);
    printf("(*b): go to address in b, returns value: %d\n", *b);
    printf("(&a): The address of a  is: %p\n", &a);
    printf("&b): the address of b is: %p\n", &b);
    
    int tmp = *a;
    printf("tmp = *a, meaning the value at the address in a is stored in tmp:  %i\n", tmp);
    *a = *b;
    printf("*a = *b, go to address in b, copy value to address stored in a:  %i\n", *a);

    *b = tmp;
    printf("*b = tmp, value at *b is: %i\n", *b);
    printf("a is of type int * and contains the address of x: %p\n", a);
    printf("b is of type int * and contains the address of y: %p\n", b);
    
    printf("a = &y: a is a pointer with the address of: %p\n", a);
    int tmp2 = *a;
    printf("tmp = *a, meaning the value at the address in a is stored in tmp:  %i\n", tmp2);
    printf("EXIT SWAP()...\n");
}