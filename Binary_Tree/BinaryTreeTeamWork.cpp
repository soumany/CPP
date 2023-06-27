#include <iostream>
//#include<stdlib.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *middle;
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
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->middle = newNode(7);
  root->left->left = newNode(3);
  root->left->right = newNode(6);
  root->left->left->left = newNode(4);
  root->left->left->right = newNode(5);
  root->right = newNode(8);
  root->right->right = newNode(12);
  root->right->left = newNode(9);
  root->right->left->left = newNode(10);
  root->right->left->right = newNode(11);

  cout << "InOrder traversal";
  traverseInOrder(root);

  cout << "\nPerOrder traversal";
  traversePerOrder(root);

  cout << "\nPostOrder traversal";
  traversePostOrder(root);
}
