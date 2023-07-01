#include <iostream>  
using namespace std;  
  
void display(int arr[], int num)  
{  
    int i;    
    for ( i = 0; i < num; i++)  
    {  
        cout << arr[i] << " ";  
    }  
}   
void reverse(int arr[], int num)  
{  
    int i;    
    for ( i = num; i >0; i--)  
    {  
        cout << arr[i] << " ";  
    }  
    
}  
  
int main ()  
{  
 
    int arr[] = {19, 50, 15, 62, 23};  
    int num = sizeof(arr)/sizeof(arr[0]);  
     
     
    display(arr, num);  
    reverse(arr, num);
      
    return 0;   
}  