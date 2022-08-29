//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
using namespace std;
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task 
{
	TaskType type; // Laundry, dishes, etc.
	int taskID;
	char* description;
};

struct TaskQueue
{
	Task* task;
	TaskQueue* nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
TaskQueue* Head = NULL;

bool enqueue(TaskQueue*& queue, const Task& task);
const Task* dequeue(TaskQueue*& queue);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS

bool enqueue(TaskQueue*& queue, const Task& task)
{ 
	

	TaskQueue *Head;

	if( *(task.description) == 0)
	   return false;

	Task *temp = new Task;
	temp->type = task.type;
	temp->taskID = task.taskID;
	temp->description = task.description;

	if( queue == NULL) 
	{	
		queue = new TaskQueue;
		queue->task = temp;
	    queue->nextInQueue = NULL;
	    return true;	
	}

    if( queue->task == NULL)
    {  
	    queue->task = temp;
	    queue->nextInQueue = NULL;
	    return true;
    }
		Head = queue;
     
	do
	{
		if(Head->task->type == temp->type || Head->task->taskID == temp->taskID)
			return false;
		Head = Head->nextInQueue;

	}while(Head != NULL);

	Head = queue;

    while((Head->nextInQueue) != NULL)
    {
    	Head = Head->nextInQueue;
    }
    TaskQueue* tmp = new TaskQueue;
    tmp->task = temp;
    tmp->nextInQueue = NULL;
    (Head -> nextInQueue) = tmp;
   // cout<< Head->nextInQueue << endl;
    return true;
 }


const Task* dequeue(TaskQueue*& queue)
{   
	if(!queue)
	 	
	 	return NULL;
	if(queue->task == NULL)
		return NULL;
	Task  *temp = queue->task;
	TaskQueue *tmp = new TaskQueue;
	tmp = queue;
	queue = queue->nextInQueue; 
    delete tmp;
    tmp = NULL;
	return temp;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//	
#ifndef MARMOSET_TESTING

int main(){
	// Some test driver code here ....
	cout << endl << "Implement some more appropriate tests in main()" << endl << endl;
	
	char sampleDescription[] = "Classsssss";
	char sampleDescription1[] = "TESTTTT";

	Task task1 =
	{
		.type = LAUNDRY,
		.taskID = 1,
		.description = sampleDescription	
	};
	Task task2 = 
	{
	    .type = DISHES,
		.taskID = 2,
		.description = sampleDescription1
	};

	//cout << task1.description << endl;

	TaskQueue* p_queue = new TaskQueue;
	p_queue = NULL;
	bool enqueueSuccess = enqueue(p_queue, task1);
	if(enqueueSuccess)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 

    bool enqueueSuccess1 = enqueue(p_queue, task1);
	if(enqueueSuccess1)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 

	 bool enqueueSuccess2 = enqueue(p_queue, task2);
	if(enqueueSuccess2)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 


	//const Task* p_firstTaskInQueue = dequeue(p_queue);
	const Task* p_firstTaskInQueue = dequeue(p_queue);
	const Task* p_firstTaskInQueue1 = dequeue(p_queue);
	const Task* p_firstTaskInQueue2 = dequeue(p_queue);
	if (p_firstTaskInQueue)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_firstTaskInQueue->type << endl;
		cout << "Task ID: " << p_firstTaskInQueue->taskID << endl;
		cout << "Description: " << p_firstTaskInQueue->description << endl;
	}
	if (p_firstTaskInQueue1)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_firstTaskInQueue1->type << endl;
		cout << "Task ID: " << p_firstTaskInQueue1->taskID << endl;
		cout << "Description: " << p_firstTaskInQueue1->description << endl;
	}
	if (p_firstTaskInQueue2)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_firstTaskInQueue2->type << endl;
		cout << "Task ID: " << p_firstTaskInQueue2->taskID << endl;
		cout << "Description: " << p_firstTaskInQueue2->description << endl;
	}

	else
		cout << "dequeue() failed" << endl;

//	delete p_queue;
	delete p_queue;
	
	return 0;
}
#endif

