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
// Important: do not include your struct, class into MARMOSET_TESTING!!!

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task 
{
	TaskType type; // Laundry, dishes, etc.
	int taskID;
	char* description;
};

//////////////////////////////////////////////////////////////
//
// Class definitions, do not remove.
//
class TaskQueue{
public:
	//it maybe a good idea to have a constructor
	bool enqueue(const Task& task)
	{
	//TaskQueue* queue = this;
	Queue* Head;
    
    if( *(task.description) == 0)
	    	return false;

		Task *temp = new Task;

		temp->type = task.type;
		temp->taskID = task.taskID;
		temp->description = task.description;
		//cout << "THEvadis" << endl;
		if( queue == NULL) 
		{
			queue = new Queue;
			queue->task = temp;
			queue->next = NULL;
			return true;	
		}

        if( queue->task == NULL)
		{  
		  queue->task = temp;
		  queue->next = NULL;
		  return true;
		}

		//	     cout << "SDf" << endl;

		  Head = queue;
		  Queue* tmp = new Queue;
          tmp->task = temp;
    	  tmp->next = NULL;
    	  do
		  {//	cout << " pokmon0 0" << endl;
		   	if(Head->task->type == temp->type || Head->task->taskID == temp->taskID)
				return false;
			Head = Head->next;
	      }while(Head != NULL);

	      Head = queue;
    	  while(Head -> next != NULL)
    	    Head = Head->next;
    	  Head->next = tmp;
    	  return true;
	
 
       //cout << " WANG DA BA" << endl;

	/*float Result = AssTask(task,Head);
	if(Result == -1)
	{
      return false;
	}
    return true;*/
    }  


 // you can either implement your function here or below in the function definitions


	const Task* dequeue()
    { 

	if(!queue)
	  return NULL;
	Task  *temp = queue->task;
	Queue *tmp = queue;
	queue = queue->next ; 
    delete tmp;
    tmp = NULL;
	return temp;
	//return NULL;
    }



	TaskQueue()
	{
		queue = NULL;
	}

	~TaskQueue()
	{ 
		delete queue;
	}
 
private:

struct Queue
{
	Task* task;
	Queue* next;
};

Queue* queue ;

};


#ifndef MARMOSET_TESTING

int main()
{
	// Some test driver code here ....
	cout << endl << "Implement some more appropriate tests in main()" << endl << endl;
	
	char sampleDescription[] = "sample description";

	Task task1 =
	{
		.type = LAUNDRY,
		.taskID = 1,
		.description = sampleDescription
	};

	TaskQueue* taskQueue = new TaskQueue();

	bool enqueueSuccess = taskQueue->enqueue(task1);
	if(enqueueSuccess)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 

	const Task* p_firstTaskInQueue = taskQueue->dequeue();
	cout << "VAT" << endl;
	if (p_firstTaskInQueue)
		cout << "Dequeue successful..." << endl; // customize your own cout since you are customizing your private members of the class.
	else
		cout << "dequeue() failed" << endl;

	

	delete taskQueue;

	
	return 0;
}
#endif

