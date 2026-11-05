#include <iostream>

// ===== Valid overloads of foo =====

// 1) No parameters, returns void
void foo()
{
    std::cout << "foo() called\n";
}

// 2) One int parameter, returns void
void foo(int x)
{
    std::cout << "foo(int) called with x = " << x << "\n";
}

// 3) Two int parameters, returns int
int foo(int x, int y)
{
    std::cout << "foo(int, int) called with x = " << x << ", y = " << y << "\n";
    return x + y;
}

// 4) One double parameter, returns double
double foo(double x)
{
    std::cout << "foo(double) called with x = " << x << "\n";
    return x * 2.0;
}

// 5) char and int parameter, returns void
void foo(char c, int count)
{
    std::cout << "foo(char, int) called: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << c << ' ';
    }
    std::cout << "\n";
}

/*
 ===== INVALID overloading example (DOES NOT COMPILE) =====

 The following function would be an attempt to overload foo
 by only changing the return type (parameter list is the same
 as double foo(double)):

    int foo(double x)
    {
        return static_cast<int>(x);
    }

 This is NOT allowed in C++ because function overloading
 is based only on the parameter types and number of parameters.
 The return type is NOT considered for overload resolution.

 If you uncomment the function above, the compiler will give
 an error like "redefinition of 'foo(double)'" or
 "functions that differ only in their return type cannot be overloaded".
*/

int main()
{
    foo();                 // calls void foo()
    foo(42);               // calls void foo(int)

    int sum = foo(10, 20); // calls int foo(int, int)
    std::cout << "sum = " << sum << "\n";

    double d = foo(3.14);  // calls double foo(double)
    std::cout << "d = " << d << "\n";

    foo('A', 5);           // calls void foo(char, int)

    return 0;
}
