#include <iostream>
using namespace std;

// Create two function headers: loadStr, strDisp
char* loadStr(int maxSize);
void strDisplay(char **ptr, int size);

// Main program
int main(){
	// Set the maximum number of strings and string length to handle
	const int N = 5;
	const int MAX_LENGTH = 100;

	char **textLines; 			// Double pointer to handle an array of strings
	textLines = new char*[N]; 	// Create N pointer entries

	// For each pointer entry, load a string
	for (int i=0; i<N; i++)
		// One-line command to load a variable-sized string
		// for each pointer array entry
		textLines[i] = loadStr(MAX_LENGTH);
	
	// Another one-line command to display 
	// all text strings in the pointer array to the screen
	cout << endl << "You have entered the following text strings: " << endl;
	strDisplay(textLines,N);
	return 0;
}

// List out the steps of loadStr()
char* loadStr(int maxSize){
	// 1. Create a string buffer
	char buffer[maxSize];

	// 2. Get one line of input text from the user (note: NULL termination not included)
	int size = 0;
	while (cin.peek() != '\n' && size < maxSize){
		buffer[size] = cin.get();
		size++;
	}
	while (cin.get() != '\n');	// Extra cin.get() calls to flush past the end of line
	
	// 3. Define a new char pointer variable
	char *strPtr;
	
	// 4. Dynamically allocate a char array with size equal to length of input text line
	//    (Include an extra character for the NULL character)
	strPtr = new char[size+1];
	
	// 5a. Copy the text line from the buffer to the char pointer
	for (int i = 0; i < size; i++)
		strPtr[i] = buffer[i];
	
	// 5b. Add a null character to the end of string
	strPtr[size] = '\0';
	
	// 6. Return the address of the char pointer as the function output
	return strPtr;
}

// List out the steps of strDisplay()
void strDisplay(char **ptr, int size){
	// Set a loop to cout each line on a line-by-line basis
	for (int i=0; i<size; i++)
		cout << ptr[i] << endl;
}