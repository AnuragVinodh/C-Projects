#include <iostream>
using namespace std;

class Rectangle
{
	private:
		int length;		//in feet
		int width;		// in feet
		float thickness;	// in fractions of inches
		
	public:	
		//default constructor to set all data members  to 0 
		Rectangle ()
		{
			length = 0;
			width = 0 ;
			thickness = 0;
		}
		
		//Print one Rectangle at a time to the console
		void printRect()const
		{ 
		 cout << "Length :" << length << endl;
		 cout << " Width :" << endl;
		
		}
		
		//set this Rectangle 's data members to those in the parameters
		Rectangle(int len, int w, float thick);
		
		//set this Rectangle 's data member to be those of the Rectangle in the parameter
		Rectangle(const Rectangle & r);
		
		//compare this Rectangle 's area to another Rectangle’s area. 
		//Return -1 if this Rectangle 's area is larger than that of the parameter
		//Return 0 if this Rectangle 's area is equal to that of the parameter received.
		// return +1 if this Rectangle 's area is smaller than that of the parameter.
		int compare(const Rectangle & r) const;	
	
		// compare this Rectangle’s perimeter  (sum of length and width) with an integer. 
		// Return true if the same. Otherwise return false
		bool compare(int i)const; 

		//Write another compare method to compare the thickness of two rectangles.
	
};

int main(const argc, const char* const argv[])
{
	// declare a rectangle using the default constructor
	

	// test other constuctors/methods one at a time before proceed to the next method

	return 0;
}