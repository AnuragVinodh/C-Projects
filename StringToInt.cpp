//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include<cmath>
#include<limits.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool stringToInt(const char input[], int& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool stringToInt(const char input[], int& value) 
{  
  enum numType {UNKNOWN,SDIGIT , DIGIT , NOTDIGIT};

  value = 0;
  numType State = UNKNOWN;
  bool Done = true;
  int i =0;
  int j =0;
  long int pukima = 0;

  if((input[0] == '-' || input[0] == '+'))
  {
    State = SDIGIT;
    j++;
  }
  
 while (input[i] != '\0' && input[j] != '\0')
 {
  //cout << "pokemon" << input[i] << endl;

 switch(State)
 {
    case UNKNOWN: if( (int)input[i] >= 48 && (int)input[i] <= 57 )
                  {
                   State = DIGIT;
                  }
                  else 
                  {
                   State = NOTDIGIT;
                  }
                  ++i;
                  break;


    case DIGIT: if( (int)input[i] >= 48 && (int)input[i] <= 57 )
                   {

         //           cout <<"DIGIT:" << i <<endl;
                    State = DIGIT;
                   }
                   
                   else
                   {
                    
       //             cout <<"NOTDIGIT : DIGIT CALL"<<endl;
                    State = NOTDIGIT;
                   }
                   ++i;
                   break;

    case SDIGIT: if( (int)input[j] >= 48 && (int)input[j] <= 57 )
                   {
     //               cout << "BAKA";
                    State = SDIGIT;
                   }
                    else
                    {
                      State = NOTDIGIT;
                    }
                    ++j;
                    break;

    case NOTDIGIT: Done = false;
                  ++i ;
                  ++j ;
   //                cout << "taj";
                   break;

 }
//cout << " bs" << input[i]<<endl;
}

if(Done == false)
{
  return false;
}

if(State == DIGIT)
{
  for(int k = 0 ; input[k] != '\0' ; ++k)
  {
    if( pukima > INT_MAX || -pukima < -INT_MAX)
     return false;
    pukima += ((int)input[k] - (int)'0')*(pow(10,i-1));
    --i;
  }
  //if( value+ (int)input[k] - (int)'0')*(pow(10,j-2) > INT_MAX)
     //return false;
    if( pukima > INT_MAX || -pukima < -INT_MAX)
     return false;

   value = pukima;
  return true;
}

else if(State == SDIGIT)
{
  for(int k = 1 ; input[k] != '\0' ; ++k)
  {
   if( pukima > INT_MAX || -(pukima) < -INT_MAX)
     return false;

    pukima += ((int)input[k] - (int)'0')*(pow(10,j-2));
    --j;
  }
    if( pukima > INT_MAX || -pukima < -INT_MAX)
     return false;
   value = pukima;
  //if( value + (int)input[k] - (int)'0')*(pow(10,j-2)> INT_MAX)
     //return false;

  if(input[0] == '-')
    value = -1*value;

  return true;

}

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

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  int argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
    return -1;
  }

  if (stringToInt(argv[1],argv1)) 
    cout << "argv[1] is an int with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not an int." << endl;
  return 0;
}

#endif
