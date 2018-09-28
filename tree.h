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
  Tree() : head(nullptr), nodes(0) {};
  void insert(T data) {
    if (!this->head) {
      Node<T> *node = new Node<T>(data);
      this->head = node;
    } else {
      Node<T>* node = new Node<T>(data) ;
      Node<T> **temp = &head;
      while (*temp) {
        temp = node->data > (*temp)->data ? &((*temp)->right) : &((*temp)->left);
      }
      *temp = node;
    }
  }
  Iterator<T> begin() {
    Node<T> *temp = new Node<T>(this->head);
    std::stack<Node<T>*> initialstack;
    initialstack.push(this->head);
    while (temp->left) {
      temp = temp->left;
      initialstack.push(temp);
    }
    return Iterator<T>(temp, initialstack);
  }
  Iterator<T> end() {return Iterator<T>(nullptr);}
};

#endif
