#include "iterator.h"
#include "node.h"
#include "tree.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

int main(void) {

  Tree<int> t;
  Tree<int> b;
  int values[10] = {17, 10, 4, 8, 6, 5, 7, 82, 18, 101};
  vector<int> sorted(values, values + sizeof values / sizeof values[0]);
  sort(sorted.begin(), sorted.end());

  for (auto i : values) {
    t.insert(i);
    b.insert(i);
  }

  Iterator<int> it = t.begin();

  t.print();
  for (auto i : sorted) {
    cout << "*it : " << *it << "  |   value : " << i << endl;
    ++it;
  }
  cout << endl;
  cout << (t.remove(17) ? "found" : "not found") << endl;

  sorted.erase(remove(sorted.begin(), sorted.end(), 17), sorted.end());
  vector<int>::iterator i;

  Iterator<int> nt;
  for (nt = t.begin(), i = sorted.begin(); nt != t.end(), i != sorted.end();
       ++nt, ++i) {
    cout << "*it : " << *nt << "  |   value : " << *i << endl;
  }

  cout << endl;
  vector<int>::reverse_iterator j;
  nt.printstack(0);
  for (nt = t.rbegin(nt), j = sorted.rbegin();
       nt != t.rend(), j != sorted.rend(); --nt, ++j) {
    cout << "continue" << endl;
    cout << "*it : " << *nt << "  |   value : " << *j << endl;
  }

  t.print(1);
  cout << endl;
  t.print(0);

  t.clear();

  t.print(1);
  cout << endl;
  t.print(0);

  return 0;
}
