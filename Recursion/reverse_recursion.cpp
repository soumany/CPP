#include <iostream>
using namespace std;

void reverseNumber(int number)
{
    // base-case
    if(number < 10){
        cout<<number;
    }

    // general-case
    else{
        cout<<number%10;
        reverseNumber(number/10);
    }
}
int main()
{
    // create variable
    int number;

    // ask user to input
    cout<<"enter your number: ";
    cin>>number;

    //calling function
    reverseNumber(number);

    return 0;
}
