/**
 * Assignment 1 : C concepts of pass by value vs reference
 *                C concepts of struct and union
 */

#include <cassert>
#include <iostream>
using namespace std;

// Swap two integers by value, without using temporary
void swap(int x, int y)
{
  cout << __func__ << ": BEFORE SWAP: x = " << x << ", y = " << y << endl;
  x = x + y;   // a=5, b=10  : a = a + b=15,  b = a -b=15-10 = 5, a = a - b = 15-5 = 10
  y = x - y;
  x = x - y;
  cout << __func__ << ": AFTER SWAP: x = " << x << ", y = " << y << endl;
  return;
}

// Swap two integers by reference, using temporary variable
void swap_ref(int* x, int* y)
{
  assert(x != nullptr && y != nullptr);
  cout << __func__ << ": BEFORE SWAP: x = " << *x << ", y = " << *y << endl;
  int tmp = *x;
  *x = *y;
  *y = tmp;
  cout << __func__ << ": AFTER SWAP: x = " << *x << ", y = " << *y << endl;
}

// Call both variants of pass-by-value and pass-by-reference
int main()
{
  int a = 5, b = 10;
  cout << __func__ << ": BEFORE SWAP: a = " << a << ", b = " << b << endl;
  swap(a, b);
  cout << __func__ << ": AFTER swap-by-val SWAP: a = " << a << ", b = " << b << endl;
  swap_ref(&a, &b);
  cout << __func__ << ": AFTER swap-by-ref SWAP: a = " << a << ", b = " << b << endl;
  return 0;
}
