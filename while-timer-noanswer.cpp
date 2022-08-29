#include <ctime>
#include <iostream>
using namespace std;

int main(){
	// 1. Get counter end point input from user
	unsigned int lastNum;
	cout << "Enter the end point of the coutner: ";
	cin >> lastNum;

	// 2. Log the start time and start while loop
	clock_t tStart, tEnd;
	double tElapsed;

	tStart = clock();
    int x=0;
	while(x<lastNum)
	++x;



	// 3. Log the end time
	tEnd = clock();

	// 4. Calculate time elapsed
	tElapsed = (double)(tEnd - tStart) / CLOCKS_PER_SEC;

	// 5. Output time required
	cout << endl << "The time elapsed is: " << tElapsed << " s" << endl;

	return 0;
}
