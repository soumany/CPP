#include <iostream>
using namespace std;

int main()
{
    int* ptr;
    // declare variables
    int var = 7;
    int foo = 21;
    int& ref = var;
    ptr = &var;
    ref = foo;
    

    // print address of var1
    cout << "Address of var1: "<< foo << endl;

    // print address of var2
    cout << "Address of var: " << var << endl;

    cout << "ref = " << ref << '\n';
    return 0;
}