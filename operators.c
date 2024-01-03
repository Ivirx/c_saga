#include <stdio.h>

int main()
{
    int i;
    int o = i;
    // int o = i = 45;
    printf("Value of i and o : %d\n and %d\n", i, o);

    int a, b, c;
    a = b = c = 10;
    printf("Sum : %d\n", a + b + c);

    int x, y, z;
    x = y = z = a + b * c;
    printf("Sum : %d\n", x + y + z);

    printf("Divide : %d\n", 10 / 3); // Gives integer value
    printf("Divide : %d\n", -10 / 3);
    printf("Divide : %d\n", 10 / -3);
    printf("Modulus : %d\n", 10 % 3);
    printf("Modulus : %d\n", -10 % 3);
    printf("Modulus : %d\n", 10 % -3);

    printf("Int : %d\n", 10 / 2);
    printf("Float : %f\n", 10.2 / 3);
    printf("Float : %f\n", 10 / 2.1);

    // Conversion
    int p = 1.333;
    printf("Int : %d\n", p);

    float q = 1;
    printf("Float : %d\n", (int)q);

    // Relational Operators
    printf("Greater : %d\n", 10 > 3);
    printf("Lesser : %d\n", 10 < 3);
    printf("Greater or Equal : %d\n", 10 >= 3);
    printf("Lesser or Equal : %d\n", 10 <= 3);
    printf("Equal : %d\n", 10 == 3);
    printf("Not Equal : %d\n", 10 != 3);

    // Logical Operators
    printf("Logical AND : %d\n", 10 && 3);
    printf("Logical OR : %d\n", 10 || 3);
    printf("Logical NOT : %d\n", !10);

    printf("0 false, 1 true : %d\n", 0 && -3.4);   // 0 is false, anything else is true
    printf("0 false, 1 true : %d\n", 'c' && -3.4); // 0 is false, anything else is true

    // Shorthand Operators
    int r = 10;
    r += 3;
    printf("Shorthand '+=' : %d\n", r);
    r -= 4;
    printf("Shorthand '-=' : %d\n", r);
    r *= 2;
    printf("Shorthand '*=' : %d\n", r);
    r /= 2;
    printf("Shorthand '/=' : %d\n", r);
    r %= 3;
    printf("Shorthand '%%=' : %d\n", r);

    // Increment and Decrement
    int s = 10;
    printf("Increment : %d\n", s++);
    printf("Increment : %d\n", ++s);
    printf("Decrement : %d\n", s--);
    printf("Decrement : %d\n", --s);

    return 0;
}