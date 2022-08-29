#include "tuple.h"
#include "set.h"
#include "invariant.h"
#include <iostream>
#include <limits.h>   // needed for INT_MIN

using namespace std;

// Set up an error set to be returned as necessary
const Set emptySet(0,(int*)0);
const Set errorSet(-1,(int*)0);




bool Set::isEmpty() const {
  return (this->_numElements == 0);
}







bool Set::isError() const {
  return false;
}
 



 
int Set::cardinality() const {
  return _tupleArraySize;
}












Set Set::union_(const Set& s) const {
	
  int newSize = this->_numElements + s._numElements;
  Tuple Result[newSize];
  
  for(int i = 0; i < (this ->_numElements) ; i++){
	Result[i] = this->_pTuples[i];
  }
  
  for(int i = (this->_numElements), j=0 ; i < (newSize) ; i++,j++){
	Result[i] = s._pTuples[j];
  }
  
  Set newSet(newSize , Result);
  return newSet;
  
}















Set Set::intersection(const Set& s) const {
	
	int newSize = this->_numElements > s._numElements? this->_numElements : s._numElements;
	Tuple Result[ newSize ];
	int count = 0;
	
	for (int i = 0 ; i < (this->_numElements) ; i++){
		for (int j =0 ; j<(s._numElements) ; j++){
				 
			if(this->_pTuples[i] == s._pTuples[j]){
				 Result[i] = this->_pTuples[i];
				 ++count;
			}
		}
	}
	
	Set newSet( count, Result);
	return newSet;
}














Set Set::difference(const Set& s) const {
	int count = 0;
	bool check = true;
	int newSize = this->_numElements > s._numElements? this->_numElements : s._numElements;
	Tuple inters[newSize];
	Tuple Result[this->_numElements];
	
	for(int  k = 0 ; k < (intersection(s)._numElements) ; ++k)
		inters[k] = intersection(s)._pTuples[k];
	
	for (int i = 0, k =0 ; i < (this->_numElements) ; i++){	
		for(int j =0; j < (newSize); j++){
			
			if( _pTuples[i] == inters[j])
					check = false;
				
	    }
		if(check == true){
			Result[k] = _pTuples[i];
			++k;
			++count;
		}
	}
	
	Set newSet( count ,Result);
	return newSet;
}

















Set Set::select(predicate* p) const {
	Tuple Result[this->_numElements]
	for(int i = 0 , k = 0; i < this->_numElements; ++i){
		if(p(this-_pTuples[i])){
			Result[k] = _pTuples[i];
			++k;
		}
	}
	Set newSet( count ,Result);
	return newSet;
}





















Set Set::project(const int numItems, const int items[]) const {
	Tuple Result[numItems];
	for(int i = 0 ; i < numItems ; ++i)
	{
		Result[i] = this->_pTuples[i].project(numItems,items);
	}
	
	Set newSet( numItems ,Result);
	return newSet;

}





















Set Set::cartesian(const Set& s) const {
	
	int newSize = (this->_numElements * s._numElements);
	Tuple Result[newSize];
	
	if(s._numElements < 0 ){
		return (*this);
	} else {
		
		for( int i = 0 , k = 0; i < this->_numElements ; ++i){		
			
			for(int j = 0; j < s._numElements ; ++j){				
				Result[k] = this->_pTuples[i] + s._pTuples[j];
				++k;
			}
			
		}
	}
	Set newSet( newSize ,Result);
	return newSet;
}


















Set Set::operator()(const int item) const {
  return emptySet;
}

void Set::operator=(const Set& s) {
	if(s._numElements < 0 ){
		this->_numElements = 0;
		this->_tupleArraySize = s._tupleArraySize;
		this->_pTuples = NULL;
	} else {
		this->_numElements = s._numElements;
		this->_tupleArraySize = s._tupleArraySize ;
		for(int  i = 0 ; i < s._numElements ; ++i){
			this->_pTuples[i] = s._pTuples[i];
		} 
	}
}














Set::Set() {
	_numElements = 0;
	_tupleArraySize = 0;
	_pTuples = NULL;
}

















Set::Set(const Set& s) {
	_numElements = s._numElements;
	_tupleArraySize = s._tupleArraySize;
	_pTuples = s._pTuples;
}
















Set::Set(const int numElements, const int data[]) {
 
	if(numElements < 0){ 	
		_numElements = 0;
		_tupleArraySize = 0;
		_pTuples = NULL;
	} else {
		_numElements = numElements;
		int i = 0;
		Tuple T[numElements];
		_pTuples = new Tuple[_numElements];
		while(i<numElements){
			T[i] = Tuple(data[i]);
			_pTuples[i] = T[i];	
			++i;	   
		}
		/* for int(i = 0 ; i < (_numElements-1) ; i++){
				for int(j =i ; j<(_numElements-1) ; j++){
					if(T[i] == T[j]){
						for(int k = j; k < (_numElements-2) ; k++){
							T[k]=T[k+1];
						}
					}
				}
		} */
		_tupleArraySize = 0;
	}
	
}






















Set::Set(const int numElements, const Tuple tuples[]) {
	if(_numElements < 0){
		
		_numElements = 0;
		_tupleArraySize = 0;
		_pTuples = NULL;
		
	} else {
		
		_numElements = numElements;
		_tupleArraySize = numElements;
		int  i = 0;
		_pTuples = new Tuple[_numElements];
		
		while( i < (_numElements) ){
			_pTuples[i] = tuples[i];
			++i;
		}
	}
}







Set::~Set() {
	if(!_pTuples)
		delete[] _pTuples;
}





std::ostream& operator<<(std::ostream& os, const Set& s) {
	if(s._numElements < 0 ){
		cout << "{}";
	} else {
		cout << "{" ;
		for (int i = 0 ; i < (s._numElements) ; ++i){
			cout <<  s._pTuples[i];
			if(!(i == s._numElements-1))
				cout << ",";
		}
		cout << "}" ;
	}
	
}
