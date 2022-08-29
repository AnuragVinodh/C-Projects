//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
#include<cmath>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN() 
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

/*{
  return x*x;
}
float fY(const float x)*/

						 
bool hitTargetGivenAngle (const float h, const float m, const float theta, const float d, const float step, const float k, const float t, const float b, const float w, float& v);











/*float bisectionHelper(const float left, const float right,const float precision, const float minIntervalSize, int count, const float step) 
{
  float deltaV;

  float mid = (right + left)/2;

  float interval = right - left;

  deltaV = mid*step;

  if(isnan(f(left)) || isnan(f(right)) || isnan(f(mid)))
    return -1;
  
   if (count == 10000)
  {
    return std::numeric_limits<float>::quiet_NaN();
  }

  if(fabs(f(mid)) <= precision || fabs(interval) <= minIntervalSize )
  {
    return mid;
  }

else
{
  if (f(mid)*f(right) > 0) 
  {
    bisectionHelper(left, mid, precision, minIntervalSize, count + 1);
  } 
  else
  {
    bisectionHelper(mid, right, precision, minIntervalSize, count + 1);
  }
}

}*/










/*float bisection(const float left, const float right,const float precision, const float minIntervalSize,const float step) 
{
    if( isnan(f(left)) || isnan(f(right)) || precision <= 0 || minIntervalSize <= 0 || left >= right || f(right) * f(left) > 0)
    {
      return std::numeric_limits<float>::quiet_NaN();
    }

     return bisectionHelper(left , right,precision,minIntervalSize, 0 , step);  
    
} */













bool hitTargetGivenAngle (const float h, const float m, const float theta, const float d, const float step, const float k, const float t, const float b, const float w, float& v) 
{
   if( h < 0 ||  m < 0 || d < 0 || w < 0 || b < 0 || step < 0 || theta < 0 || k < 0)
       return false;


  bool done = false;
  float rad  = (theta*M_PI)/180; 
  float num = 4.9*pow(d,2);
  float denum =  pow(cos(rad),2)*((h-t)+(tan(rad)*d));
  float v1 = sqrt(num/denum);
 
 ///cout << " initial velocity : " << v1 << endl;
  float ground = 0;
  float Vmax = v1*3;
  float Vmin = 0;
  float precision = 0.001;
  float minIntervalSize = 0.001;
  float interval,mid,deltaV,vX,vY,airAccX,airAccY;

  float distX = 0;
  float distY = h;

  int i = 0;
  int j = 0;

  while (  fabs(distX - d) > 0.001 )
  {
    mid = (Vmax+Vmin)/2 ; 
  
    vX = mid*cos(rad);
    vY = mid*sin(rad);
    
  //  cout << vX << " VX " << endl;
   // cout << Vmin << " Vmin " << endl;
   // cout << Vmax << " Vmax " << endl;
   // cout << mid << " mid " <<  endl;
     if( i > 100) 
     {   
     break;
     }
    //cout << mid << " new velocity " << endl;
    j = 0;
    distX = 0 ;
    distY = h ;
    //cout << distX << " dist outside " << endl;

    while(  distY > t || vY > 0 || !done || j < 1000)
    {
      ++j;
      float v2 = sqrt((vX*vX)+(vY*vY));

      airAccX = -((k*v2*vX)/m);
      airAccY = -((k*v2*vY)/m);
        vX = vX + airAccX*step;


      distX = distX + vX*step;
      distY = distY + vY*step;

    // cout << endl << vX*step << " stepped dist " << endl;
    // cout << endl << distX << " distX " << endl;
     
   //  cout << vX << " <- vX " << endl;

      vY = vY + (airAccY-9.8)*step;

      if(distY < 0 && (distX<b || distX > (b+w)))
        done = true;
    

      //cout << vY << " <- vY " << endl;
    

    }
    if(distX > d )
    {
     // cout << "pokemon" << endl;
      Vmax = mid;
    }
    else
    {
      //cout << "pokeeee" << endl;
      Vmin = mid;
    }
   i ++;
   

  }

  //bisection(Vmax,Vmin,precision,minIntervalSize,step)
 
 v = mid;  
  return true ;

}
		













#ifndef MARMOSET_TESTING
int main() {
	
  // Some test driver code here ....
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 0;
  float w = 30;
  float m = 0.5;
  float step = 0.01;
  float k = 0.03;
  float theta = 68.81; // Angle in degrees;
  float v = 25;	

  cout << endl << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, step, k, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity" << endl << endl;
  }
    
  return 0;
}
#endif
