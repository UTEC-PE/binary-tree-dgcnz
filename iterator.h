#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> class Iterator {
private:
  Node<T> *current;

public:

  std::stack<Node<T>*> nodes;
  Iterator() { current = nullptr; }
  Iterator(Node<T> *node) { this->current = node; }
  Iterator(Node<T> *node, std::stack<Node<T>*> initialstack) {
    this->current = node;
    this->nodes = initialstack;
  }
  Iterator<T> operator=(Iterator<T> node) {
      this->nodes = node.nodes;
      this->current = node.current;
  }
  bool operator!=(Iterator<T> cmp) { return (this->current != cmp.current); }
  Iterator<T> operator++() {
    bool moved = 0;
    (this->nodes).pop();
    if(this->current->right)  {
        moved = 1;
        this->current = this->current->right;
        current_to_stack();
        while(this->current->left){
            this->current = this->current->left;
            current_to_stack();
        }
    }
    if(!moved){
        this->current = (nodes.top());
    }


  }
  void current_to_stack(){
      (this->nodes).push(this->current);
  }
  Iterator<T> operator--() {}
  T operator*() { return (this->current->data); }
};

#endif
