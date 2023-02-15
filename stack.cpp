#include <iostream>
#include <stack>
using namespace std;
int main() {
    system ("cls");
    stack<int> myStack;
    // The values pushed in the stack should be of the same
    // data which is written during the declaration of stack
    myStack.push(21);
    myStack.push(32);
    myStack.push(24);
    myStack.push(29);
    myStack.push(15);
    myStack.push(34);
    myStack.push(45);
    cout<< endl;
    cout << "The size of my stack: "<< myStack.size()<< endl;
    if (myStack.empty()==0)
   {
        cout << "My stack is not empty" << endl;
   }
   else
   {
        cout << "My stack is empty" << endl;
   }
    myStack.pop();
    myStack.pop();
    myStack.pop();
    
    int num=10;
    myStack.push(num);
    cout << "The current element in my Stack:" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() <<" ";
        myStack.pop();
    }
}


