/**
 * Assignment 3 : template classes and functions
 */

#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template<class T>
void f(T& t)
{
    cout << t << ", ";
}

template <class T>
struct Database {
  void add(T& a) { db.push_back(a); }
  void print() {
    for_each(db.begin(), db.end(), f<T>);
    cout << endl;
  }
  private:
  list<T> db;
};

Database<int> keys_db;
void add_key(int key) {
  keys_db.add(key);
}

// Call both variants of pass-by-value and pass-by-reference
int main()
{
  int keys[] = {1, 3, 5, 7};
  cout << "No of keys = " <<  sizeof(keys)/sizeof(keys[0]) << endl;
  for_each(keys, keys+sizeof(keys)/sizeof(keys[0]), add_key);
  keys_db.print();
  return 0;
}
