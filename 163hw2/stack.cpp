#include "stack.h"
//stack.cpp file
//all the class stack functions are defined by this file.

//constructor
stack::stack()
{
	head = NULL;		//initialize the head node pointer 
	top_index = NULL;	//initialize the top_index pointer
}
//destructor
stack::~stack()
{
	if(!head)
		return;
	node*temp = head; 	//pointer, for hold the head address 
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		if(temp->data)
			delete [] temp->data;
		delete temp;
	}

}
//This function is for adding people in the stack list
//each new statistic record will be added to a top hole of a array of a current head node.
//input:: a stat struct passed from service class with the worst time and average time data.
int stack::push(const stat & to_add)
{
	node* temp = NULL;	//pointer, for holding the current head node address
	if(!head)		//if the stack is empty
	{	
		head = new node;		//create a new node.
		head->data= new stat[MAX];	//create a new stat type dynamic array in the new head node.
		head->next = NULL;		
		top_index = head->data;		//use top pointer to point the first hole of the array.
		*top_index = to_add;		//dereferance, copy the data from input to the array.
		
		++top_index;			//make pointer point to the next hole.
		return 1;
	}
	if(top_index == & head->data[MAX])	//Full case, if the pointer point to the position already over the last hole of the array
	{
		temp = head;			//hold the current head node.
		head = new node;		//create a new head
		head -> next = temp;		//add the new head at the beginning of the list. 
		head->data= new stat[MAX];	//create a new dynamic array.
		top_index = head->data;		//make pointer point to the top hole.
		*top_index = to_add;		//dereferance, copy the data from the input to the array. 
		++top_index;			//pointer point to the next hole.
		return 1;
	}
	else					//neither empty or full case
	{
		*top_index = to_add;		//copy data from the input to the array
		++top_index;			//point to the next hole.
		return 1;
	}
	return 0;
}
//This function is for removing the top hole of a array data of the stack.
//if I need to modify the top data of the stack, I should pop it first.  
int stack::pop (void)
{
	node * hold = NULL; 		//pointer, for holding the next node of the head address
	if(head == NULL)		//if the stack is empty
	{
		return 0;
	}
	if(top_index == head->data)		//if there is just the last hole data
	{			
		hold = head->next;		//hold the next node address
		if(head->data)			//check the array is not empty before deleting it
			delete [] head->data;		//delete it
		delete head;			//delete the head node data
		head = hold;			//set the hold node be the head node 
		top_index = &head->data[MAX];	//set the pointer to point over the last hole(full case)
		return 1;
	}
	else
	{
		--top_index;			//neither empty or last hole case
		return 1;
	}
}
//This function is for checking and getting the top data of the stack.
//input:: a struct passed by service class. it will get the top data back service and do comparison job.  
int stack::peek(stat & top)const
{
	if(!head)			//if the stack is empty
		return 0;
	stat* peek_top = top_index;	//a local pointer, copy from the top_index pointer. top_index pointer won't change. 
	top = *(--peek_top);		//dereferance, copy from the top data to the top struct passed in
	
	return 1;
}
//This function is for displaying data of array of the head node stack.
//I use this function to test whether my stack class works or not.
int stack::display()const
{		
	 if(!head)
		return 0;
	 stat* display_head = top_index;
	 --display_head;
	 while(display_head != head->data)
	 {
		cout<<"-----------------------"<<endl;	
	 	cout<<"The worst wait time : " <<  (*display_head).wait_time <<endl;
		cout<<"Average time : " << (*display_head).average_time <<endl;
		--display_head;		
	 }
	 cout<<"The worst wait time : " <<  (*display_head).wait_time <<endl;
	 cout<<"Average time : " << (*display_head).average_time <<endl;
	 cout<<"------------------------------" <<endl;
	 return 1;
}
