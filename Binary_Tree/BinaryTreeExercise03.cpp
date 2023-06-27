#include <iostream>
//#include<stdlib.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}
void traversePerOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePerOrder(temp->left);
    traversePerOrder(temp->right);
  }
}

void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->right);
    traversePostOrder(temp->left);
    cout << " " << temp->data;
  }
}
int main() {
  struct node *root = newNode('A');
  root->left = newNode('B');
  root->left->left = newNode('D');
  root->left->right = newNode('E');
  root->left->left->left = newNode('H');
  root->left->left->right = newNode('I');
  root->right = newNode('C');
  root->right->right = newNode('G');
  root->right->left = newNode('F');

  cout << "InOrder traversal";
  traverseInOrder(root);

  cout << "\nPerOrder traversal";
  traversePerOrder(root);

  cout << "\nPostOrder traversal";
  traversePostOrder(root);
}
