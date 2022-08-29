#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int A[], int arraySize){
for(int i = 0; i <= arraySize-1; i++) {
    cout << A[i] << " ";
}
cout << endl;
  }

void swap(int a[], int b[]){
	int* temp = a;
	a = b;
	b = temp;
}

void selectionSort(int nums[], int start, int end);

void selectionSortHelper(int numbers_to_sort[], int size){
  selectionSort(numbers_to_sort, 0, size);
}


void selectionSort(int nums[], int start, int end)
{
    if ( start >= end )
        return;
    int minIndex = start;
    for ( int index = start + 1; index < end; index++ )
    {
        if (nums[index] < nums[minIndex] )
            minIndex = index;
    }
    swap(nums[start], nums[minIndex]);

    selectionSort(nums, start + 1, end);
}

int main(const int argc, const char* argv[]){

  int length=9;
  int nums[9] = {4,230,31,2,56,3,2,32,5};


  cout << "Before sorting" << endl;
  printArray(nums,9);

  selectionSortHelper(nums, length-1);

  cout << "After sorting" << endl;
  printArray(nums,9);
}
