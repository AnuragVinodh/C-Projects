#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue(){
	head = NULL;
	tail = NULL;
}

Queue::~Queue(){
}

void Queue::enqueue(int number){
	Item* curr = new Item;
	curr->num = number;
	curr->next = NULL;
	if (head == NULL)
		head = tail = curr;
	else{
		tail->next = curr;
		tail = curr;
	}
}

bool Queue::dequeue(int& number){
	if (head == NULL)
		return false;
	Item* curr = head;
	number = curr->num;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete curr;
	return true;
}

void Queue::print(){
	Item* curr = head;
	for (; curr != NULL; curr=curr->next)
		cout << curr->num << " ";
	cout << endl;
	return;
}
