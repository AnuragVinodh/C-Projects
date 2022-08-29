//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h
   #include<math.h>
   #include<float.h>

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
//#define po(a) pow(10,a) 
bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...

bool stringToFloat(const char input[], float& value) 
{
  enum numType {UNKNOWN,SIGNED,NOTSIGNED,AFTERPOINT,AFTERPOINTS,E,ENOT,NOTFLOAT};
  value = 0;
  numType State = UNKNOWN;
  bool sign = false;
  bool Done  = true;
  int i = 0;
  int k = 1;
  double Value1;
 // cout << "in file" << endl;
   //long int pukima  = 0;

  if((input[0] == '-' || input[0] == '+'))
  {
    State = NOTSIGNED;
    if(input[0] == '-')
    sign = true;
    i++;
  }

  while(input[i] != '\0' && Done != false)
  { 
    //cout << "i value : " << i << endl;
 
  switch(State)
  {
      case UNKNOWN:    if( (int)input[i] >= 48 && (int)input[i] <= 57 )
                        {
                         Value1 *= 10;
                         Value1 += ((int)input[i] - (int)'0');
                         if( Value1 + ((int)input[i] - (int)'0') > FLT_MAX || Value1 + ((int)input[i] - (int)'0') <FLT_MIN || Value1 + ((int)input[i] - (int)'0') < -FLT_MAX || Done == false )
                       {
                        //cout << "Batmasdasd" << endl;
                        return  false;
                       }
                      //  
                        //cout << "value :" << value << endl;
                        State = NOTSIGNED;
                        }
                        else if(input[i] == '.') 
                        {
                         State = AFTERPOINT;
                        }
                        else if(input[i] == 'e' || input[i] == 'E')
                        {
       //                   cout << "batan" << endl;
                          Done = false;
     //                     cout << "Done Value :" << Done << endl;
                        }
                        else
                        {
   //                      cout << "pokemon";
                          State = NOTFLOAT;
                          Done = false;
                        }
                        ++i;
                        break;


      case NOTSIGNED: if( (int)input[i] >= 48 && (int)input[i] <= 57 )
                      {
                      Value1 *= 10;
                      Value1 +=  ((int)input[i] - (int)'0');
                      /*if( Value1 + ((int)input[i] - (int)'0') > FLT_MAX || Value1 + ((int)input[i] - (int)'0') <FLT_MIN || Value1 + ((int)input[i] - (int)'0') < -FLT_MAX || Done == false )
                      {
                        //cout << "Batmasdasd" << endl;
                        return  false;
                       }*/
                      //  cout<< "n not signed :" << Value1 << endl;
                      }
                      else if(input[i] == '.') 
                      {
                        State = AFTERPOINT;
                      }
                      else if(input[i] == 'e' || input[i] == 'E')
                      {
                         if (input[i+1] == '\0')
                        {
                          Done == false;
                          return false;
                        }
                        State = E;
                      }
                      else
                      {
                        State = NOTFLOAT;
                        Done = false;
                      }
                      ++i;
                      break;



      case AFTERPOINT:if( (int)input[i] >= 48 && (int)input[i] <= 57 )
                      {
                       Value1 += (float)((input[i] - '0')/(pow(10.0,k)));
                       /*if( Value1 +(float)((input[i] - '0')/(pow(10.0,k)))  > FLT_MAX || Value1 +(float)((input[i] - '0')/(pow(10.0,k))) <FLT_MIN || Value1 +(float)((input[i] - '0')/(pow(10.0,k))) < -FLT_MAX || Done == false )
                       {
                        //cout << "Batmasdasd" << endl;
                        return  false;
                       }*/
                    //  cout << "value after point :" << Value1 << endl;
                    //  cout << "k = " << k << endl;
                      }
                      else if(input[i] == 'e' || input[i] == 'E')
                      {
                        if (input[i+1] == '\0')
                        {
                          Done == false;
                          return false;
                        }
                        //cout << "spidermann" << endl;
                        State = E; 
                      }
                      else
                        {
                          State = NOTFLOAT;
                          Done = false;
                        }
                      ++i;
                      ++k;
                      break;


       case E:      //cout << "pokemon";
                     if((input[i] == '-'  ))  
                    {
                      if((int)input[i+1] >= 48 && (int)input[i+1] <= 57)
                      {  
                      Value1 *= pow(10,-((int)input[i+1] - (int)'0'));
                     /* if(  Value1 * pow(10,-((int)input[i+1] - (int)'0')) > FLT_MAX || Value1 * pow(10,-((int)input[i+1] - (int)'0')) <FLT_MIN || Value1 * pow(10,-((int)input[i+1] - (int)'0')) < -FLT_MAX || Done == false )
                      {
                        //cout << "Batmasdasd" << endl;
                         return  false;
                      }*/

                      i+=2;
                      }     
                      else
                      {
                        Done = false;
                        i+=2;
                      }

                    }
                    else if((input[i] == '+'))
                    {
                      if((int)input[i+1] >= 48 && (int)input[i+1] <= 57)
                      {
                      Value1 *= pow(10,((int)input[i+1] - (int)'0'));
                      //cout << "Done" << Done << endl;
                   /*if(  Value1 * pow(10,-((int)input[i+1] - (int)'0')) > FLT_MAX || Value1 * pow(10,-((int)input[i+1] - (int)'0')) <FLT_MIN || Value1 * pow(10,-((int)input[i+1] - (int)'0')) < -FLT_MAX || Done == false )
                     {
                        //cout << "Batmasdasd" << endl;
                        return  false;
                      }*/
                      i+=2;
                      }
                      else
                      {
                        Done = false;
                        i+=2; 
                      }  
                    }
                    else if((int)input[i] >= 48 && (int)input[i] <= 57)
                    {
                      //cout <<  value << "," << input[i] << "," << (int)input[i];
                      Value1 *= pow(10,((int)input[i] - (int)'0'));
                      //cout << "Done" << Done << endl;
                     /*if(Value1 * pow(10,-((int)input[i+1] - (int)'0')) > FLT_MAX || Value1 * pow(10,-((int)input[i+1] - (int)'0')) <FLT_MIN || Value1 * pow(10,-((int)input[i+1] - (int)'0')) < -FLT_MAX || Done == false )
                     {
                      //cout << "Batmasdasd" << endl;
                      return  false;
                     }*/
                      ++i;
                    }
                    else
                    {
                      State = NOTFLOAT;
                      Done = false;
                      ++i;
                    }
                    break;


    case NOTFLOAT: Done = false;
                   return false;
                   ++i; 
                   break;

  }
}
//cout << "Done" << Done << endl;
if(Value1 > FLT_MAX || Value1 <FLT_MIN || Value1 < -FLT_MAX || Done == false )
{
  //cout << "Batmasdasd" << endl;
  return  false;
}
else
{

 /// cout << "Jadeon Fan" ;
  value = Value1;
}
 if(Done == true && sign == false)
 { 
 //cout << "aoijoi";
  return true;
 }
 else if(Done == true && sign == true)
 {
 //cout <<"asdas";
  value *= -1;
  return true;
 }
 if(Done == false)
 {
  //cout << "pokemon in Error" << endl;
  return false;
 }
else
{
  //cout << "jassdasd" ;
   return false;
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
int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1)) 
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
