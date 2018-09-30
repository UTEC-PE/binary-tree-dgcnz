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
  bool insert(T data) {
    Node<T> **nodeptr;
    bool found = (this->find(data, nodeptr));
    if (!(this->head)) {
      Node<T> *node = new Node<T>(data);
      this->head = node;
      (this->nodes)++;
      return 1;
    } else if (!found) {
      Node<T> *node = new Node<T>(data);
      *nodeptr = node;
      (this->nodes)++;
      return 1;
    } else {
      return 0;
    }
  }
  bool remove(T data) {
    Node<T> **fatherptr;

    if (!this->find(data, fatherptr)) {
      return 0;
    }

    Node<T> *leftptr = (*fatherptr)->left;
    Node<T> *rightptr = (*fatherptr)->right;

    delete *fatherptr;

    if (leftptr && rightptr) {
      *fatherptr = leftptr;
      while (leftptr->right) {
        leftptr = leftptr->right;
      }
      leftptr->right = rightptr;
    } else if (leftptr || rightptr) {
      *fatherptr = leftptr ? leftptr : rightptr;
    } else {
      *fatherptr = nullptr;
    }
    (this->nodes)--;
    return 1;
  }
  bool find(T data, Node<T> **&nodeptr) {
    nodeptr = &head;
    if (!this->head) {
      return 0;
    } else {
      while ((*nodeptr)->data != data) {
        nodeptr = data > (*nodeptr)->data ? &((*nodeptr)->right)
                                          : &((*nodeptr)->left);
        if (!(*nodeptr)) {
          return 0;
        }
      }

      return 1;
    }
  }
  void clear() {
    if (this->head) {
      this->head->killSelf();
    }
    this->head = nullptr;
  }
  void print(bool direction = 1) {
    // direction = 1 : inorder, else : opposite order
    if ((this->head)) {
      if (direction) {
        Iterator<T> it = this->begin();
        for (it; it != this->end(); ++it) {
          std::cout << *it << " ";
        }
      } else {
        Iterator<T> it = this->rbegin();
        for (it; it != this->rend(); --it) {
          std::cout << *it << " ";
        }
      }
      std::cout << "\n";
    } else {
      std::cout << "Empty Tree\n";
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

  Iterator<T> rend() { return Iterator<T>(nullptr); }
  Iterator<T> rbegin(Iterator<T> it = Iterator<T>()) {
    if (!(it.isEmpty())) {
      Iterator<T> nt;
      nt.initReverse(it);
      return nt;
    } else {
      Node<T> *temp = new Node<T>(this->head);
      std::stack<Node<T> *> initialstack;
      initialstack.push(this->head);
      while (temp->right) {
        temp = temp->right;
        initialstack.push(temp);
      }
      return Iterator<T>(temp, initialstack);
    }
  }

  ~Tree() { this->clear(); }
};

#endif
