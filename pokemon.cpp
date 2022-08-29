#include <iostream>
#include<stdio.h>
using namespace std;
void strSet(char* target, const char* source){
	
	while(*source){

		*target++ = *source++;
	}

}

void swap2(int* num1, int* num2){

	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;

}
int main()
{
  int value = 10;
  const int* ptr = &value;
  int k = 12;
  cout << ++(ptr) << endl;
  int i = 0;
  cout << i++ << " " << i++ << " " << ++i << endl;
  cout << "VF " << i << endl;
  cout << *ptr;
}