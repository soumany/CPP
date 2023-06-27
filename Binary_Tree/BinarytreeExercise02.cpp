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
  struct node *root = newNode(2);
  root->left = newNode(7);
  root->left->left = newNode(2);
  root->left->right = newNode(6);
  root->left->right->left = newNode(5);
  root->left->right->right = newNode(11);
  root->right = newNode(5);
  root->right->right = newNode(9);
  root->right->right->left = newNode(4);

  cout << "InOrder traversal";
  traverseInOrder(root);

  cout << "\nPerOrder traversal";
  traversePerOrder(root);

  cout << "\nPostOrder traversal";
  traversePostOrder(root);
}
