#include <iostream>
using namespace std;

// node creation
struct node {
  int data;
  struct node* next;
  struct node* prev;
};
int main() {
 

    //if don't use malloc
    //if you malloc doens't have new node()
    node *head =new node();
    node *firstnode= new node();
    node *secondnode = new node ();
    node *thirdnode = new node();
    node *tail = new node();

    
    // head = (struct node *)malloc(sizeof(struct node));
    // firstnode = (struct node *)malloc(sizeof(struct node));
    // secondnode = (struct node *)malloc(sizeof(struct node));
    // thirdnode = (struct node *)malloc(sizeof(struct node));
    // tail = (struct node *)malloc(sizeof(struct node));

   //head
    head ->data = 19;
    head ->prev = NULL;
    head ->next = firstnode;

  //Firstnode
    firstnode ->data = 50;
    firstnode ->prev = head;
    firstnode ->next = secondnode;

  //Secondnode
    secondnode ->data = 15;
    secondnode ->prev = firstnode;
    secondnode ->next = thirdnode;

  //thirdnode
    thirdnode ->data = 62;
    thirdnode ->prev = secondnode;
    thirdnode ->next = tail;

    //tail
    
    tail ->data = 23;
    tail ->prev =  thirdnode;
    tail -> next = NULL;

    

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    
    cout<<endl;
    while(tail != NULL){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    return 0;


}