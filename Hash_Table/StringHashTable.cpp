#include <iostream>
#include <string>
#include <list>
using namespace std;

class hashTable
{
    private:
        int BUCKET;
        list<string> *table;

    public:
        hashTable(int bucketSize){
            this->BUCKET = bucketSize;
            table = new list<string>[BUCKET];
        }

        void insert(const string& key)
        {
            int index = hashFunction(key);
            table[index].push_back(key);
        }

        void remove(const string& key){
            int index = hashFunction(key);
            list<string>::iterator it;
            for(it = table[index].begin(); it != table[index].end(); it++){
                if(*it == key){
                    table[index].erase(it);
                    break;
                }
            }
        }

        bool search(const string& key){
            int index = hashFunction(key);
            list<string>::iterator it;
            for(it = table[index].begin(); it != table[index].end(); it++){
                if(*it == key){
                    return true;
                }
            }
        }

        void display(){
            for(int i=0; i<BUCKET; i++){
                cout<<i<<":";
                for(auto it = table[i].begin(); it != table[i].end(); it++){
                    cout<<*it<<"-->";
                }
                cout<<"NULL"<<endl;
            }
        }

    private:
        int hashFunction(const string& key){
            int hashValue = 0;
            for(char c : key){
                hashValue += c;
            }
            return hashValue % BUCKET;
        }
};

int main()
{
    hashTable hashTable(10);

    hashTable.insert("Som sokdana");
    hashTable.insert("Sok cheapanha");
    hashTable.insert("Seng veha");
    hashTable.insert("Sao pongpechpenhchey");
    hashTable.insert("Sou many");

    cout<<"Hash Table after inserting data:"<<endl;
    hashTable.display();
    cout<<endl;

    hashTable.remove("Seng veha");

    cout<<"Hash Table after deleting data:"<<endl;
    hashTable.display();
    cout<<endl;

    hashTable.insert("Phea Dalen");
    hashTable.insert("Soeurm Ravit");
    hashTable.insert("Sothea Monineath");

    cout<<"Hash Table with collisions:"<<endl;
    hashTable.display();
    cout<<endl;

    cout<<"Searching for Sok cheapanha: "<<(hashTable.search("Sok cheapanha")?"Found":"Not Found")<<endl;
    cout<<"Searching for Sarath vechyney: "<<(hashTable.search("Sarath vechyney")?"Found":"Not Found")<<endl;

    return 0;
}
