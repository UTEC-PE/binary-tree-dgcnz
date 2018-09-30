#ifndef TREE_H
#define TREE_H

#include "iterator.h"
#include "node.h"
#include <iostream>
#include <stack>
#include <string>

template <typename T> class Tree {
private:
  Node<T> *head;
  int nodes;

public:
  Tree() : head(nullptr), nodes(0){};
  void insert(T data) {
    if (!this->head) {
      Node<T> *node = new Node<T>(data);
      this->head = node;
    } else {
      Node<T> *node = new Node<T>(data);
      Node<T> **temp = &head;
      while (*temp) {
        temp =
            node->data > (*temp)->data ? &((*temp)->right) : &((*temp)->left);
      }
      *temp = node;
    }
    (this->nodes)++;
  }
  bool remove(T data) {
    Node<T> **fatherptr;

    if (!this->find(data, fatherptr)) {
      return 0;
    }

    Node<T> *leftptr = (*fatherptr)->left;
    Node<T> *rightptr = (*fatherptr)->right;

    std::cout << "father: " << (*fatherptr)->data << "\nleft: "
              << (leftptr ? std::to_string(leftptr->data) : "nullptr")
              << "\nright: "
              << (rightptr ? std::to_string(rightptr->data) : "nullptr")
              << std::endl;

    delete *fatherptr;

    if (leftptr && rightptr) {
      std::cout << "case both\n";
      *fatherptr = leftptr;
      while (leftptr->right) {
        leftptr = leftptr->right;
      }
      leftptr->right = rightptr;
    } else if (leftptr || rightptr) {
      std::cout << "case one\n";
      *fatherptr = leftptr ? leftptr : rightptr;
    } else {
      std::cout << "case leaf\n";
      *fatherptr = nullptr;
    }
    (this->nodes)--;
    return 1;
  }
  bool find(T data, Node<T> **&nodeptr) {
    nodeptr = &head;
    if (!this->head) {
      nodeptr = nullptr;
      return 0;
    } else {
      while ((*nodeptr)->data != data) {
        if (data > (*nodeptr)->data) {
          nodeptr = &((*nodeptr)->right);
        } else {
          nodeptr = &((*nodeptr)->left);
        }
        if (!(*nodeptr)) {
          nodeptr = nullptr;
          return 0;
        }
      }

      return 1;
    }
  }
  Iterator<T> begin() {
    Node<T> *temp = new Node<T>(this->head);
    std::stack<Node<T> *> initialstack;
    initialstack.push(this->head);
    while (temp->left) {
      temp = temp->left;
      initialstack.push(temp);
    }
    return Iterator<T>(temp, initialstack);
  }
  Iterator<T> end() { return Iterator<T>(nullptr); }
};

#endif
