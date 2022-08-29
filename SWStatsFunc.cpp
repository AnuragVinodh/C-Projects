//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <float.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn) {
			
		float minimum , maximum , average;
		
		int SWMinimum(dataset,size,currentSample,windowSize,minimum)
	  
		int SWMaximum(dataset,size,currentSample,windowSize,maximum) 
			
		int SWAverage(dataset,size,currentSample,windowSize,average)
			
		min = minimum;
		max = maximum;
		avg = average;
			
}



float min = FLT_MAX;
int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum) {
			  
			 
			 if(counter <= windowSize )
			 {
				if(dataset[counter] < min)
					min = dataset[counter];
				
				
			 }
			 else
			 {
				 min = FLT_MAX;
				 for( int i = (counter - windowSie)+1 ; i <= windowSize ; i++)
				 {
					 if( dataset[i] < min )
						 min = dataset[i];
				 }
				 
			 }
			 minimum = min;
			  
			  
			  
}
flaot sum = 0;
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average) {
			  
			  if( counter <= windowSize)
			  {
				  sum += dataset[counter];
				  sum = sum + dataset[0]*j;
				  average = sum/windowSize;
				  sum -= dataset[0]*j
				  
			  }
			  else
			  {
				sum = 0;
				for( int i = (counter - windowSie)+1 ; i <= windowSize ; i++)
				 {
					 sum += dataset[i];
				 }
				 average = sum/windowSize;
				
				  
			  }
}



float max = FLT_MIN;
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum) {
			  			  
			 
			 if(counter <= windowSize )
			 {
				if(dataset[counter] > max)
					max = dataset[counter];
				
				
			 }
			 else
			 {
				 min = FLT_MAX;
				 for( int i = (counter - windowSie)+1 ; i <= windowSize ; i++)
				 {
					 if( dataset[i] > max )
						 max = dataset[i];
				 }
				 
			 }
			 maximum = max;
			  
			  

}

int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev) {
}

int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median) {
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
  int size = 5;
  float dataset[] = {1, 2, 3, 4, 5};
  int windowSize = 2;
  int currentSample = 0;
  float min;
  float avg;
  float max;
  float smplSD;
  float median;

  cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }
    ++currentSample;
  }
  return 0;
}

#endif
