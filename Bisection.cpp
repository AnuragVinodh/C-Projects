//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include<limits>
#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,const float precision, const float minIntervalSize);
float bisection(const float left, const float right,const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right,const float precision, const float minIntervalSize)
{

 
	int i;
	++i;
	
	 

	float mid;
	float val = f(mid);


    mid = (left/2)+(right/2);

    	if (f(mid) == numeric_limits<float>::quiet_NaN())
    	{
    		return numeric_limits<float>::quiet_NaN();
    	}

    	
       if( i > 1000)
         return mid;
	
	 int num = f(mid);


   if((f(mid) - num) < precision || (right - left) < minIntervalSize)
   	return mid;


   //int num = f(mid);
	
	if(f(mid) < 0)
	{
		bisectionHelper(mid, right, precision, minIntervalSize );
	}
	else
	{
		bisectionHelper(left, mid, precision, minIntervalSize  );
	}



}

float bisection(const float left, const float right,const float precision, const float minIntervalSize) 
{
	

	float mid =bisectionHelper(left , right , precision , minIntervalSize );

	return mid;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) 
{
 
  float minInt , prec , right , left;

  
  minInt = atof(argv[1]);
  prec = atof(argv[2]);
  left = atof(argv[3]);
  right = atof(argv[4]);

  float mid =  bisection(left, right, prec, minInt);
	

	cout << "root is :" << f(mid);
  
  return 0;
}

#endif
