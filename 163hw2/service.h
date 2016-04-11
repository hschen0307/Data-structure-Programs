#include <cctype>
#include <cstring>
#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;
//service.h file,//This files manages stack.cpp file's class members, function prototypes and private members.

//This class manages stack class and queue class. it makes them can work together.
//when removing the people,queue and stack need to be used at the same time.
//so there are two objects in this class, one is for using stack, another is for using queue.
//I also create two more private members, people amount and current average time. for easily managing my statistic part.
class service
{
	public:
		//prototypes
		service();	//constructor
		~service();	//destructor
		int add_person(node_q * & add);		//for adding people to the waiting list. 
		int remove_person(int time_use);	//removing people from the waiting list and manage the statistic job at the same time.
		int find_out_person(node_q * & add);	//for checking there is the first customer in the waiting list or not.	
		int find_out_statistic(stat & top);	//for checking there is the top statistic data in the stack or not.
	private:
		//private member
		queue customer;				//object, for using queue's functions
		stack timer;				//object, for using stack's funtions
		int people;				//for counting total people already served 
		float average_time;			//for counting the average time
};

