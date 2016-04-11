#include "queue.h"
//queue.cpp file 
//all the class queue functions are defined by this file.

//constructor
queue::queue()
{
	rear = NULL; //initialize the rear node pointer
}
//destructor
queue::~queue()
{
	if(!rear);
		return;
	
	node_q* current;		
	current = rear->next;	
	rear->next = NULL;		//open the circular link list for deallocating
	while(current)		//traverse until the end of the list
	{
		rear = current -> next;		//hold the next node
		if(current->name)
			delete [] current->name;
		if(current->order)
			delete [] current->order;
		delete current;			//delete the current node
		current = rear;			//reset the current node 
	}
}
//This function is for adding people in the queue list
//each new customer node will be added in the last position of the list.
//input:: a node_q node 'add' passed from service class with a customer information.
int queue::enqueue(node_q * & add)
{
	node_q * temp = new node_q;				//open a new node_q node
	temp->name = new char[strlen(add->name)+1];		//copy all infromation from node 'add'
	strcpy(temp->name, add->name);				
	temp->order = new char[strlen(add->order)+1];
	strcpy(temp->order, add->order);
	temp->arrival_h = add->arrival_h;
	temp->arrival_m = add->arrival_m;
	
	if(!rear)			//check the rear is NULL or not, if NULL, set the node being the first node of the list
	{
		rear = temp;
		rear ->next = temp;
		return 1;	
	}
	temp->next = rear->next;	//if the node is not second node, add the node in the end of the list.
	rear->next = temp;
	rear = temp;
	return 1;			
}
//This function is for removing people in the queue list.(waiting list)
//it just remove the first one person in the list at each time.
//input:: a int array for geting the arrival time out before removing people
//output:: the int array get the arrival time out
int queue::dequeue(int get_time[])
{
	node_q* temp;	//pointer, for holding the first node address, and then delete it. 

	if(rear == NULL)	//checking the list whether is empty or not.
	{
		return 0;
	}

	get_time[1] = rear->next->arrival_h;	//for getting the arrival hour
	get_time[2] = rear->next->arrival_m;	//for getting the arrival minutes

	if(rear->next == rear)			//if there is one node case
	{
		if(rear->name)			//check there is information in name or order in the array or not before deleting it.
			delete [] rear->name;	//delete name
		if(rear->order)
			delete [] rear->order;	//delete order
		delete rear;			//delete the node

		rear = NULL;			//set rear pointing to NULL
		return 1;			
	}
	temp = rear->next;			//if over one node case
	rear->next = temp->next;		
	if(rear->name)				//check there is information in name or order in the array or not before deleting it.
		delete [] temp->name;
	if(rear->order)
		delete [] temp->order;
	delete temp;	
	return 1;
}
//This function is for geting information from the first person in the list.
//so it also can check there are people in the list or not. 
//If the list is empty, it will return 0. User can know there is no people in the list.
//input::a node_q node for geting the information of the first node.
int queue::peek(node_q *& get_first)
{
	if(!rear)		//if the list is empty.
	{
		return 0;
	}
	if(get_first->name)			//check the name or order array is not empty before deleting it
		delete [] get_first->name;
	if(get_first->order)
		delete [] get_first->order;
	get_first->name = new char[strlen(rear->next->name)+1];		//copy all the information from the first node of the list.
	strcpy(get_first->name, rear->next->name);
	get_first->order = new char[strlen(rear->next->name)+1];
	strcpy(get_first->order, rear->next->order);
	get_first->arrival_h = rear->next->arrival_h;
	get_first->arrival_m = rear->next->arrival_m;
	return 1;
}
//THis function can display the waiting list. I use this function to check my queue function works or not
int queue::display()
{
	node_q *current;
	if(rear == NULL)
	{
		return 0;
	}
	current = rear->next;
	while(current != rear)
	{
		cout<< "Name : "<< current->name <<endl;
		cout <<"Order : " << current->order <<endl;
		cout<< "The arrival time is : " << current->arrival_h<< ":"<< current->arrival_m<<endl;
		current = current -> next;
	}
	cout<< "Name : "<< current->name <<endl;
	cout <<"Order : " << current->order <<endl;
	cout<< "The arrival time is : " << current->arrival_h<< ":"<< current->arrival_m<<endl;

	return 1;
}
