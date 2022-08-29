#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main( const int argc, const char*const argv[] ) {
	
	if (argc < 4) {
		cerr << "Error: Insufficient arguments; expecting three command-line arguments" << endl;
		return -1;
	} else if (argc > 4) {
		cerr << "Warning: Expecting three command-line arguments; received " << argc - 1 << "; ignoring extraneous arguments" << endl;
	}
	
	float v = atof(argv[1]);
	float d = atof(argv[2]);
	float max_decel = fabs(atof(argv[3]));
	
	float min_a =  fabs(pow(v,2)/(2*d));
	float min_t =  fabs(v/min_a);
	
	if((d*v < 0) || (v == 0)) {
		cout << "There is no possibility of collision because the car is not moving towards the obstacle" << endl;
	} else if(min_a <= max_decel) {
		cout << "Initial car velocity: "  << v     << " m/s"   << endl; 
		cout << "Distance to obstacle: "  << d     << " m"     << endl;
		cout << "Minimum deceleration: "  << min_a << " m/s/s" << endl;
		cout << "Maximum stopping time: " << min_t << " s"     << endl;
	} else {
		float v_f;
		float time;
		if (v < 0 && d < 0) {
			v = -v;
			d = -d;
			v_f = -(sqrt(v*v-2*max_decel*d));
			time = (v_f + v)/-max_decel;
		} else {
			v_f = (sqrt(v*v-2*max_decel*d));
			time = (v_f - v)/-max_decel;
		}
		cout << "Crash will occur in " << time << " seconds at velocity " << v_f << " m/s; deploying airbags." << endl;
	}
}

