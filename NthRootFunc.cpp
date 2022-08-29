//////////////////////////////////////////////////////////////

#include <limits>
#include <stdlib.h>

//////////////////////////////////////////////////////////////


#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

float NthRoot(const float S, const int N, const float precision) 
{
	
if( (S < 0 && N % 2 == 0 ) || N < 2 || precision <= 0)
	{
		return std::numeric_limits<float>::quiet_NaN();
	}
	if( S == 0 )
	{
		return 0;
	}
	
	float s = S ;
	int Root = N;
	float Precision = precision;
	float P;
	
	float r = S;
	
	do {
		
		float tmp = 1;
		int i = 0;
		while ( i < N-1 ) {
			tmp *= r; 
			i++;
		}
		
		r = ((N - 1)*r)/N + S/(N*tmp);
		
		tmp = 1;
		i = 0;
		while ( i < Root)
	    {
		    tmp *= r;
		    i++;
	    }
		
		P = (S - tmp)/S;
		
		if( P < 0 )
			P = -P;
     
	} while ( P >= Precision );
		
	return r;
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
  
  if (argc < 4) 
  {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;

  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl; 

  return 0;
}

#endif
