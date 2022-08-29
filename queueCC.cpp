#include <iostream>
#include "queueCC.h"
using namespace std;

Queue::Queue(){
	head = NULL;
	tail = NULL;
}

Queue::Queue(Queue& orig){
	if (orig.head == NULL)
		head = tail = NULL;
	else{
		Item* curr = orig.head;
		while (curr != NULL){
			Item* replica = new Item;
			replica->num = curr->num;
			replica->next = NULL;
			if (curr == orig.head)
				head = tail = replica;
			else{
				tail->next = replica;
				tail = tail->next;
			}
			curr = curr->next;
		}
	}
}

Queue::~Queue(){
	while (head != NULL){
		Item* curr = head;
		head = head->next;
		delete curr;
	}
	tail = NULL;
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
