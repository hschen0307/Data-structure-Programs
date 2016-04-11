#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

//queue.h file
//This file manages queue.cpp file's class members. All function prototypes and private member.
//Queue manages all current customer's waiting list.

//this node_q struct is for creating  nodes to store each customer's information of the queue list.
struct node_q
{
	char* name;		//pointer, for storing a customer's name in a dynamic array.
	char* order;		//pointer, for storing a order in in a dynamic array.
	int arrival_h;		//storing hour of arrival time 
	int arrival_m;		//storing minutes of arrival time 
	node_q* next;		//pointer, for pointing to the next node

};

//queue class manages adding, removing, and finding customers in the queue list.   
//this queue list is a linear link list. each node is each customer of the waiting list.
class queue
{
	//function prototypes
	public:
		queue(void);	//constructor
		~queue(void);	//destructor  
		
		int enqueue(node_q * & add);	//This function is for adding people to the last of the queue list. 
		int dequeue(int get_time []);	//this function is for removing the first person in the list.
		int peek(node_q *& get_first);	//for finding out whether there is a person in the list.(and it also can get the first person in the list.)
		int  display();			//this function can display the list
	//private member
	private:	
		node_q * rear;			//the end of the list position. up to it to find our whole list data.
		

};
