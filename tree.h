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
  void remove(T data) {
    Node<T>** fatherptr = this->get(data);
    Node<T>* leftptr = (*fatherptr)->left;
    Node<T>* rightptr = (*fatherptr)->right;
    (**fatherptr).~Node();
    *fatherptr = leftptr;
    while(leftptr->right){
      leftptr = leftptr->right;
    }
    leftptr->right = rightptr;
  }
  Node<T>** get(T data){
    Node<T>** nodeptr = &head;
    if(!this->head){
      return nullptr;
    }
    else{
      while((*nodeptr)->data != data){
        if(data > (*nodeptr)->data ) {
          nodeptr = &((*nodeptr)->right);
        }
        else{
          nodeptr = &((*nodeptr)->left);
        }
        if(!(*nodeptr)) return nullptr;
      }
      return nodeptr;
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
