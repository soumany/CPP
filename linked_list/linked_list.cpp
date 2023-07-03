#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

int main() {

    //head
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head ->data = 45;
    head ->link = NULL;

    cout << head -> data;

    //tail
    struct node *tail = NULL;
    tail = (struct node *)malloc(sizeof(struct node));

    tail ->data = 36;
    tail ->link = head;

    cout << tail -> data;
    return 0;
}

