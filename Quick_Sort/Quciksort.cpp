#include <iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int first_ind, int last_ind, int pivot)
{
    int i = first_ind;
		int j = first_ind;
		while( i <= last_ind){
			if( arr[i] > pivot){
				i++;
			}
			else{
				swap(arr,i,j);
				i++;
				j++;
			}
		}
		return j-1;
}

void quicksort(int arr[], int first_ind, int last_ind)
{
    if(first_ind < last_ind){
        int pivot = arr[last_ind];
        int pos = partition(arr, first_ind , last_ind , pivot);

        quicksort(arr, first_ind, pos - 1);
        quicksort(arr, pos + 1, last_ind);
    }
}

int main()
{
    int size = 8;
	int arr[size] = {8,15,4,3,18,7,1,4};
	//Array Before sort
	cout << "Before sort Array" <<endl;
	for(int i = 0 ; i < size  ; i++){
		cout << arr[i] << ", ";
	}
	cout<<endl;

	cout<< "swap index 2 with index 6" <<endl;
	swap(arr, 2, 6);
	for(int j = 0 ; j < size ; j++){
		cout << arr[j] << ", ";
	}
	cout<<endl;

	//Partition of Array
	cout<<"partition of Array" <<endl;
	partition(arr,0,7,4);
	for(int j = 0 ; j < size ; j++){
		cout << arr[j] << ", ";
	}
	cout<<endl;

	cout << "after sort array"<<endl;
	quicksort(arr , 0 , size -1);
 	for(int j = 0 ; j < size ; j++){
		cout << arr[j] << ", ";
	}

    return 0;
}
