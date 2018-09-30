#include "iterator.h"
#include "node.h"
#include "tree.h"
#include <algorithm>
#include <iostream>
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

  for (auto i : sorted) {
    cout << "*it : " << *it << "  |   value : " << i << endl;
    ++it;
  }
  cout << endl;
  Iterator<int> nt = t.begin();
  cout << (t.remove(5) ? "found" : "not found") << endl;

  sorted.erase(sorted.begin() + 1);

  cout << "erase passed" << endl;
  for (auto i : sorted) {
    cout << "*it : " << *nt << "  |   value : " << i << endl;
    ++nt; // Pasé 3 horas debuggeando todo el código y al final era solamente
          // que me había olvidado cambiar este ++it por un ++nt
  }

  return 0;
}
