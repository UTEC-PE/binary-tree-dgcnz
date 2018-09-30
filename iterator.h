#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>
#include <stack>

template <typename T> class Iterator {
private:
  Node<T> *current;
  bool reverse;
  std::stack<Node<T> *> stack_cache;
  std::stack<Node<T> *> popped_values;

public:
  Iterator() : reverse(0) { current = nullptr; }
  Iterator(Node<T> *node) : reverse(0) { this->current = node; }
  Iterator(Node<T> *node, std::stack<Node<T> *> initialstack) : reverse(0) {
    this->current = node;
    this->stack_cache = initialstack;
  }
  Iterator<T> initReverse(Iterator<T> it) {
    this->reverse = 1;
    this->current = (it.popped_values).top();
    this->popped_values = it.popped_values;
    return *this;
  }
  Iterator<T> operator=(Iterator<T> node) {
    this->stack_cache = node.stack_cache;
    this->current = node.current;
    return *this;
  }
  bool operator!=(Iterator<T> node) { return (this->current != node.current); }
  Iterator<T> operator++() {
    (this->popped_values).push((this->stack_cache).top());
    (this->stack_cache).pop();
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
  Iterator<T> operator--() {
    if (!(this->reverse)) {

      (this->popped_values).push((this->stack_cache).top());
      (this->stack_cache).pop();
      if (this->current->left) {
        moveToLeftChild();
        current_to_stack();
        while (this->current->right) {
          moveToRightChild();
          current_to_stack();
        }
      } else {
        moveToLastVisited();
      }
      return *this;
    } else {

      (this->popped_values).pop();
      if (!(this->popped_values).empty()) {
        this->current = (this->popped_values).top();
      }
      return *this;
    }
  }
  T operator*() { return (this->current->data); }

  bool isEmpty() { return this->current ? 0 : 1; }
  void moveToLastVisited() { this->current = (this->stack_cache.top()); }
  void moveToRightChild() { this->current = this->current->right; }

  void moveToLeftChild() { this->current = this->current->left; }
  void current_to_stack() { (this->stack_cache.push(this->current)); }

  void printstack(bool iscache = 1) {
    std::stack<Node<T> *> a = iscache ? this->stack_cache : this->popped_values;
    while (!a.empty()) {
      std::cout << (a.top())->data << " ";
      a.pop();
    }
    std::cout << std::endl;
  }
};

#endif
