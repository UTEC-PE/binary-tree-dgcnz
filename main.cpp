#include<iostream>
#include "node.h"
#include "tree.h"
#include "iterator.h"

using namespace std;

void printstack(stack<Node<int>*> b){
stack<Node<int>*> a = b;
while (!a.empty()) {
      std::cout<<(a.top())->data << " ";
      a.pop();
 }
cout << endl;
}

int main(void){
    
    Tree<int> t;
    int values[10] = {17, 10, 4, 8,6, 5,7,82, 18, 101};

    for(auto i : values){
        t.insert(i);
    }
    Iterator<int> it = t.begin();

    cout << *it << endl;
    printstack(it.nodes);
    cout << *(++it) << endl;

    printstack(it.nodes);
    return 0;
}
