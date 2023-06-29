#include <iostream>
using namespace std;

void reverseNumber(int number)
{
    int remaider, revNumber=0;
    while(number > 0){
        remaider = number%10;
        number = number/10;
        revNumber = (revNumber*10)+remaider;
    }
    cout<<"The Reverse Number is: "<< revNumber;
}

int main()
{
    // create variable
    int number;

    // ask user to input
    cout<<"enter your number: ";
    cin>>number;

    reverseNumber(number);

    return 0;
}
