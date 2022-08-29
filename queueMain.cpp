#include <iostream>
#include "queueCC.h"
using namespace std;

int main(){
	
	// Create a queue object
	Queue list;
	for (int i=12; i<=36; i+=12)
		list.enqueue(i);
	for (int j=0; j<=1; j++){
		Queue newList(list);
		list.print();
	}
	list.print();
	
	return 0;
}
