#ifndef NODE_H
#define NODE_H
#include <string>

template <typename T> struct Node {
  T data;
  Node *left;
  Node *right;
  Node(T data) : data(data), left(nullptr), right(nullptr) {}
  Node(Node<T> *node)
      : data(node->data), left(node->left), right(node->right) {}
  //~Node() { this->left = this->right = nullptr; }
  void killSelf() {
    if (left)
      left->killSelf();
    if (right)
      right->killSelf();
    delete this;
  }
};

#endif
