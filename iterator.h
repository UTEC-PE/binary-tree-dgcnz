#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> class Iterator {
private:
  Node<T> *current;
  std::stack<Node<T>> nodes;

public:
  Iterator() { current = nullptr; }
  Iterator(Node<T> *node) { this->current = node; }
  Iterator(Node<T> *node, std::stack<T> initialstack) {
    this->current = node;
    this->nodes = initialstack;
  }
  Iterator<T> operator=(Iterator<T> node) {}
  bool operator!=(Iterator<T> cmp) { return (this->current != cmp.current); }
  Iterator<T> operator++() {
    if(this->current->right)  {

    }
  }
  Iterator<T> operator--() {}
  T operator*() { return (this->current->data); }
};

#endif
