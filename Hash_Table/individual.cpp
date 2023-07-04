#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Hash{
    int BUCKET;
    list<int> *table;

    public:
        Hash(int V);
        void insertItem(int x);
        void deleteItem(int key);
        int hashFunction(int x)
        {
            return (x % BUCKET);
        }
        void displayHash();
};

Hash :: Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    list <int> :: iterator i;
    for (i=table[index].begin(); i != table[index].end(); i++){
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash(){
    for(int i = 0; i < BUCKET; i++){
        cout<<i;
        for(auto x : table[i])
            cout<<" --> "<< x;
        cout<<endl;
    }
}

int main()
{
    int arr[8] = {20,11,12,23,5,17,8,9};
    Hash hash = Hash(10);
    for(int i=0; i<8; i++){
        hash.insertItem(arr[i]);
    }
    cout<<"Hash Table Value: "<<endl;
    hash.displayHash();
    cout<<"Hash Table Value after remove 12: "<<endl;
    hash.deleteItem(12);
    hash.displayHash();
    cout<<"Hash Table Value after insert data collision: "<<endl;
    hash.insertItem(arr[3]=13);
    hash.insertItem(arr[7]=57);
    hash.displayHash();
    return 0;
}
