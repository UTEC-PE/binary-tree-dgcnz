#ifndef TREE_H
#define TREE_H

#include "iterator.h"
#include "node.h"
#include <iostream>
#include <stack>
template <typename T> class Tree {
private:
  Node<T> *head;
  int nodes;

public:
  Tree() {}
  void insert(T data) {
    if (!this->head) {
      Node<T> *node = new Node<T>(data);
      this->head = node;
    } else {
      Node<T> node(data);
      Node<T> **temp = &head;
      while (*temp) {
        temp = node->data > temp->data ? &((*temp)->right) : &((*temp)->left);
      }
      *temp = node;
    }
  }
  Iterator<T> begin() {
    Node<T> *temp = new Node<T>(this->head);
    std::stack<Node<T>> initialstack = {this->head};
    while (temp->next) {
      temp = temp->left;
      initialstack.push_back(temp);
    }
    return Iterator<T>(this->temp, initialstack);
  }
  Iterator<T> end() {}
};

#endif
