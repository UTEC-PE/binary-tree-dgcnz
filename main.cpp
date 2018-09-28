#include<iostream>
#include <stack>
#include "node.h"
#include "tree.h"
#include "iterator.h"
#include <algorithm>
#include <vector>

using namespace std;


int main(void){

    Tree<int> t;
    Tree<int> b;
    int values[10] = {17, 10, 4, 8,6, 5,7,82, 18, 101};
    vector<int> sorted( values, values + sizeof values / sizeof values[0] );
    sort(sorted.begin(), sorted.end());

    for(auto i : values){
        t.insert(i);
        b.insert(i);
     }


    Iterator<int> it = t.begin();
    for(auto i : sorted){
      cout << "*it : " << *it << "  |   value : " << i << endl;
      ++it;
    }
    cout << endl;

    return 0;
}
