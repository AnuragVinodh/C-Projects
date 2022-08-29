#include <iostream>
#include <fstream> 		// Include fstream
using namespace std;

int main() {
	// Define objects for input and output files
    ifstream infile; 	// Input file should be of ifstream type
    ofstream outfile; 	// Output file should be of ofstream type

	// Open: Key command to initialize the input and output files
    infile.open("Inputfile.txt");
    outfile.open("Outputfile.txt");

	// Fail flag: Asserted if the file cannot be opened (e.g. input file does not exist)
	if (infile.fail()) {
      cerr << "Error: Input file cannot be opened.\n";
      return -1;
	}
	if (outfile.fail()) {
      cerr << "Error: Output file cannot be opened.\n";
      return -1;
	}

	// All cout instructions are applicable to output file stream objects
    outfile << "Text in the input file is repeated here:" << endl;

	// Example of read-write operation on a char-by-char basis
	while(infile.peek() != EOF){
		char c = infile.get();
		outfile << c;			// Output the current character to outfile
	}

	// ADDITIONAL OPERATION: COUNT THE NUMBER OF CHARACTERS
	// 1. Move the infile stream back to the start of file
	infile.clear();				// Resets the EOF flag
	infile.seekg(0,infile.beg);	// Resets the infile stream position back to the start of file
	
	// 2. Count from the start of file to end of file
	int charCount = 0;
	int lineCount = 0;
	while (!infile.eof()){
		char c = infile.get();
		(c != '\n') ? charCount++ :	lineCount++;
	}
	// Echo results to output file
	outfile << "In the original input file, there are " 
			<< charCount << " characters (excluding line returns), and "
			<< lineCount << " lines.\n";

	// CLOSE: Key command to end access to an input or output file
    infile.close();
    outfile.close();

    return 0;
}
