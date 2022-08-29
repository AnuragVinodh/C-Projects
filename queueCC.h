#ifndef QUEUE_CC_H
#define QUEUE_CC_H

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
		void enqueue(int number);
		bool dequeue(int &number);
		void print();
};

#endif
