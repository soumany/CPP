# include <iostream>
using namespace std;

int powerWithRecursion(int base, int powerOfNumber)
{
    if(powerOfNumber == 0){
        return 1;
    }
    else{
        return (base*powerWithRecursion(base, powerOfNumber-1));
    }
}

int main(){
    // create a variables
    int base, powerOfNumber, result;

    // ask user to input base and powerOfNumber
    cout<<"Enter your base number here: ";
    cin>>base;

    cout<<"Enter your Power Of Number here: ";
    cin>>powerOfNumber;

    // display your result
    result = powerWithRecursion(base, powerOfNumber);
    cout<<base<<"^"<<powerOfNumber<<"="<<result;

    return 0;
}
