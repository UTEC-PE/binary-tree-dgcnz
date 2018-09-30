#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>
#include <stack>

template <typename T> class Iterator {
private:
  Node<T> *current;
  std::stack<Node<T> *> stack_cache;

public:
  Iterator() { current = nullptr; }
  Iterator(Node<T> *node) { this->current = node; }
  Iterator(Node<T> *node, std::stack<Node<T> *> initialstack) {
    this->current = node;
    this->stack_cache = initialstack;
  }
  Iterator<T> operator=(Iterator<T> node) {
    this->stack_cache = node.stack_cache;
    this->current = node.current;
  }
  bool operator!=(Iterator<T> node) { return (this->current != node.current); }
  Iterator<T> operator++() {
    (this->stack_cache.pop());
    if (this->current->right) {
      moveToRightChild();
      current_to_stack();
      while (this->current->left) {
        moveToLeftChild();
        current_to_stack();
      }
    } else {
      moveToLastVisited();
    }
    return *this;
  }
  void moveToLastVisited() { this->current = (this->stack_cache.top()); }
  void moveToRightChild() { this->current = this->current->right; }

  void moveToLeftChild() { this->current = this->current->left; }
  void current_to_stack() { (this->stack_cache.push(this->current)); }

  void printstack() {
    std::stack<Node<T> *> a = this->stack_cache;
    while (!a.empty()) {
      std::cout << (a.top())->data << " ";
      a.pop();
    }
    std::cout << std::endl;
  }
  Iterator<T> operator--() {}
  T operator*() { return (this->current->data); }
};

#endif
