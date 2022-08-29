#ifndef QUEUE_H
#define QUEUE_H

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
		~Queue();
		void enqueue(int number);
		bool dequeue(int &number);
		void print();
};

#endif
