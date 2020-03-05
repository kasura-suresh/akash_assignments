/*********************************************************
*
*To Implement Interface in C++
*Author: Akash Kumar Gupta
*Date: 14/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
class Shape {
   public:
      virtual int Area() = 0;
      void Height(int h) {
         height = h;
      }
      void Width(int w) {
         width = w;
      }
   protected:
      int height;
      int width;
};

class Rectangle: public Shape {
   public:
      int Area() {
         return (width * height);
      }
};
int main(void) {
   Rectangle Rect;
   Rect.Width(10);
   Rect.Height(10);
   cout << "Total Rectangle area: " << Rect.Area() << endl;
   return 0;
}
