/**
 * Assignment 2 : virtual function and polymorphism
 */

#include <cassert>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

struct Object {
  virtual string name() { return "Object"; }
};

class IntObject : public Object {
  int i{10};
  public:
  IntObject(int x = 10) : i(x) { }
  virtual string name() { return "IntObject:"+to_string(i); }
};

class CharObject : public Object {
  char c{'b'};
  public:
  CharObject(char x = 'b') : c(x) { }
  virtual string name() { return "CharObject:"+to_string(c); }
};

void name(Object* obj) {
  cout << obj->name() << endl; 
}

// Call both variants of pass-by-value and pass-by-reference
int main()
{
  list<Object*> list1;
  cout << __func__ << ": BEFORE ADD: list size = " << list1.size() << endl;
  list1.push_back(new IntObject(5));
  list1.push_back(new CharObject('a'));
  cout << __func__ << ": AFTER ADD: list contents = ";
  for_each(list1.begin(), list1.end(), name);
  return 0;
}
