#include "service.h"
//constructor
service::service()
{
	people = 0;
	average_time = 0;
}
//destructor
service::~service()
{
}
//this function is for adding people to the waiting list
//input::a node_q node from main function 
//it will be pass in enqueue fuction for adding people in queue list.
int service::add_person(node_q * & add)
{
	if(!customer.enqueue(add))	//pass the q node to the enqueue function of the queue.
	{
		return 0;
	}
	if(!customer.display())		//display the list after adding people in queue.	
	{
		return 0;
	}
	return 1;
}
//This function is for removing people from the wait list when they pay.
//it also do the statistic job at the same time.(counting the worst time and average time)
//input:: the int variable is the leave time(total minutes) passed from main function. 
int service::remove_person(int time_use)
{
	int get_time[2];	//int array, pass in the dequeue function of the queue to get the arrival time(hour,minutes) of the first customer
	int arrive_min=0;	//for counting, it is a total minutes number of arrival time
	stat to_add;		//struct,for storing the current statistic data and pass in the stack 
	stat top;		//struct,for geting the top statistic data from the stack.

	if(!customer.dequeue(get_time))		//removing people from the queue
	{
		return 0;			//no people direct return back

	}

	arrive_min = get_time[1]*60 + get_time[2];	//count total minutes from the arrival time
	time_use = time_use - arrive_min;		//use leave time total minutes minor arrival time total minutes-> length of time  
	average_time = (average_time*people + time_use);	//count the average time(my private member: average_time, people)
	++people;
	average_time = average_time/people;				
	to_add.wait_time = time_use;			//store the current data in the struct
	to_add.average_time = average_time;		

	if(!timer.peek(top)) //First case,check whther the data on the top of the stack or not, and get the data out. 
	{
		//if there is no data, add the current data in the stack. it will be the first data
		if(!timer.push(to_add))		
		{
			return 0;
		}
		if(!timer.display())	//display it after adding it
		{	
			return 0;
		}
		cout << "You already served : " << people << " people." << endl;	//current people number
		return 1;	//back to the main.
	}
	if(top.wait_time >= to_add.wait_time)	//Second case, top data is worst than add data.
	{
		if(!timer.pop())		//remove it first
		{	
			return 0;
		}
		top.average_time = average_time;	//use the top data from peek perviously. modify the average time 
		if(!timer.push(top))			//add the top to the stack
		{
			return 0;
		}
	}
	else if(top.wait_time < to_add.wait_time)	//Third case, top data is not worst than the add data.
	{
		if(!timer.push(to_add))			//directly push the add data in the stack
		{
			return 0;
		}
	}
	if(!timer.display())			//display result of the current stack
	{	
		return 0;
	}
	cout << "You already served : " << people << " people." << endl;	//total served people
	return 1;
}
//This function is for check whether there are people in the line.
//if there is a person, it will get the information back to the main.
//input::node_q node get_first passed from main for copying the information
//output::get_first will be back to the main after copying 
int service::find_out_person(node_q *& get_first)
{
	if(!customer.peek(get_first))	//call peek function of queue, pass the node_q node for copying.
	{
		return 0;
	}
	return 1;
}
//This function is for check whether there is a statistic record or not.
//if there is a record of the top , it will get the record back to the main.
//input::a stat struct passed from main for copying the record
//output::get_first will be back to the main after copying
int service::find_out_statistic(stat & top)
{
	if(!timer.peek(top))	//call peek function of stack, pass the top struct for copying
	{
		return 0;
	}	
	return 1;
}
