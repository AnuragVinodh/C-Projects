#include <math.h>
#include <iostream>

using namespace std;

/////////////////////////////////////
//
// Class definition; do not change
//

#ifndef MARMOSET_TESTING

class CartesianPoint {
  public:
    float slope(const CartesianPoint& p) const;
    float distance(const CartesianPoint& p) const;
    float triangleArea(const CartesianPoint& p2, const CartesianPoint& p3) const;
    bool  straightLine(const CartesianPoint& p2, const CartesianPoint& p3) const;

    void  printToCout() const;

    // Constructors and Destructor
    CartesianPoint();
    CartesianPoint(const CartesianPoint& p);
    CartesianPoint(const float x, const float y);
   ~CartesianPoint();
   
  private:
    float _x;
    float _y;
};

#endif

/////////////////////////////////////
//
// Constructors and Destructor
//

CartesianPoint::CartesianPoint() {
  // Your code here
}

CartesianPoint::CartesianPoint(const CartesianPoint& p) {
  // Your code here
}

CartesianPoint::CartesianPoint(const float x, const float y) {
  // Your code here
}

CartesianPoint::~CartesianPoint() {
  // Your code here
}

//////////////
//
// Methods
// (Default return values included so that this compiles without error/warning;
// you will want to change these.)
//

float CartesianPoint::slope(const CartesianPoint& p) const {
  // Your code here
  return NAN;
}

float CartesianPoint::distance(const CartesianPoint& p) const {
  // Your code here
  return NAN;
}

float CartesianPoint::triangleArea(const CartesianPoint& p1, const CartesianPoint& p2) const {
  // Your code here
  return NAN;
}

bool  CartesianPoint::straightLine(const CartesianPoint& p1, const CartesianPoint& p2) const {
  // Your code here
  return false;
}

void CartesianPoint::printToCout() const {
  // Your code here
  return;
}

#ifndef MARMOSET_TESTING
////////////////////////////////
//
// Main: Some sample testing ...
//

int main() {
  CartesianPoint p1;
  CartesianPoint p2(3.1415927,0.0010);
  cout << p1.distance(p2) << endl;

  CartesianPoint p3(314.15927,0.1000);

  cout << p1.triangleArea(p2,p3) << endl;

  cout << "p1: ";
  p1.printToCout();
  cout << endl;
  
  cout << "p2: ";
  p2.printToCout();
  cout << endl;
  
  cout << "p3: ";
  p3.printToCout();
  cout << endl;

  CartesianPoint* p4 = new CartesianPoint;
  delete p4;
  cout << "p4: ";
  p4->printToCout();
  cout << endl;

  cout << "p1-p1 slope: " << p1.slope(p1) << endl;
  cout << "p1-p2 slope: " << p1.slope(p2) << endl;
  cout << "p1-p3 slope: " << p1.slope(p3) << endl;
  cout << "p2-p3 slope: " << p2.slope(p3) << endl;

  if (p1.straightLine(p2,p3))
    cout << "P1, P2, P3 are in a straight line" << endl;
  else
    cout << "P1, P2, and P3 are not in a straight line" << endl;

  if (p1.straightLine(p1,p3))
    cout << "P1, P1, P3 are in a straight line" << endl;
  else
    cout << "P1, P1, and P3 are not in a straight line" << endl;

  CartesianPoint p6(1,0);
  CartesianPoint p7(1,-10);
  CartesianPoint p8(1,20);

  if (p6.straightLine(p7,p8))
      cout << "P6, P7, P8 are in a straight line" << endl;
  else
    cout << "P6, P7, and P8 are not in a straight line" << endl;

  
  return 0;
}
#endif
