#ifndef QUEUE_OO_H
#define QUEUE_OO_H

class Queue{
	private:
		struct Item{
			int num;
			Item* next;
		};
		Item* head;
		Item* tail;
	public:
		Queue();
		Queue(Queue& orig);
		~Queue();
		Queue& operator =(const Queue& source);
		bool operator ==(const Queue& source);
		void enqueue(int number);
		bool dequeue(int &number);
		void print();
};

#endif
