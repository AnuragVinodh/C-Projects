#include <iostream>
#include<string.h>

using namespace std;


void swap1(char* a, char* b) {
	char* tmp = a;
	a = b;
	cout << "the" <<a<< endl;;
	b = tmp;
}

void swap2(char a[], char b[]) {
	char tmp[10];
	for(int i =0 ; i < strlen(a)  ; ++i)
		tmp[i] = a[i];

	a[] = b[];
	b[] = tmp[];
}

void swap3(char* &a, char* &b) {
	char* tmp = a;
	a = b;
	b = tmp;
}


int main() {
	char name1[8] = "Crowley";
	char name2[6] = "Jadon";
	char name3[8] = "Crowley";
	char name4[6] = "Jadon";
	char name5[8] = "Crowley";
	char name6[6] = "Jadon";
	char* a = name5;
	char* b = name6;
	swap1(name1, name2);
	swap2(name3, name4);
	swap3(a, b);
	cout << "Name1: " << name1 << " " <<"Name2 :"<< name2 << " Name3: " << name3 << " Name4: "  << name4 << " Name5: " << name5 << " Name6: " << name6 << endl;

}