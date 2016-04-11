#include <cstring>
#include <cctype> 
#include <iostream> 
using namespace std;
//stack.h
//This files manages stack.cpp file's class members, function prototypes and private members.
//Stack manages the statistic part.(worst wait time and average time) 
//The stack is a linear link list of arrays.

//this stat struct is for storing wait_time and average_time in the array.
//array is a stat type dynamic array. 
struct stat
{
	int wait_time;		
	float average_time;
};
//this struct is for create nodes to found a linear link list of arrays.
struct node
{
	stat * data;//the stat type pointer for creating a dynamic array in each node
	node * next;//the next pointer	
};
//This const is for each dynamic array's size
const int MAX = 5;
//stack class manages adding, removing, and finding statistic records. When the custmer pay the bill, we will put the time information in the statistic part.
class stack
{	//function prototypes
	public:
		stack(void);	//constructor
		~stack(void);	//destructor
		int push(const stat & to_add ); //for adding the time information(worst and average) to a array of a head node.
		int pop (void);			//for removing the top of the stack list information.
		int peek(stat & top)const;	//for finding the top of the stack list information.
		int display()const;		//for display the statistic results of the head node.
	//private members 
	private:
		node * head;	//the head of the linear link list of arrays.			
		stat* top_index; //pointer, point to the current position of stat array.
};
d->data[MAX]
