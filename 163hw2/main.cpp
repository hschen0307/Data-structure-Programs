#include "service.h"
//main.cpp file, this file is creating for user to use this program.
//name:Hsuan-Chih, Chen.
//date:5/6/2015
//this program can manage a people waiting list. we can add people in the list, and remove peole from the list when they pay(queue).
//At the same time, it can store and count the worst time and arverge time from customers for doing statisic job.(stack)
//it also can check whether there are people currently in the line or not for users.

//prototypes
void create(node_q * & add); 		//for creating and typing information to a node_q node 
int cal_time();				//for calculating the total minute of leave time 
void deleter(node_q * & add);		//deallocate the two node_qs in main
void read_out(node_q * get_first);	//display the inforamtion from the first node of queue
void read_out_stat(stat get_top);	//display the record from the top of stack
void output_menu();			//for outputing the menu to users

int main()
{
	service hello;		//service object, for using service class in main.
	int choice = 0;		//int variable, store user's option		
	int menu = 0;		//int variable, control the menu working(while loop)
	int  time_use =0;	//int variable, store total minutes of leave time, and then pass to service for statistic job.
	stat get_top;		//stat struct, for passing in the stack, and get the record back.
	node_q* add = new node_q;	//node_q pointer, for passing the information of customer to the queue.
	node_q* get_first = new node_q; //node_q pointer, for getting the information from the first node of the queue.		
	
	while(menu == 0)
	{
		output_menu(); 	//menu
		cin>>choice;	//user's choice	
		cin.ignore(100,'\n');
		if(choice == 1)		//add people in the waiting list
		{	
			create(add);	//create a new customer information
			if(!hello.add_person(add))	//pass it in to the queue
			{
				cout<<"Haven't add. Please add this customer again" <<endl;
			}	
		}
		else if(choice == 2)	//remove people in the waiting list
		{
			if(!hello.find_out_person(get_first))	//check the list is empty or not first
			{
				cout<<"There is no people in the line. "<<endl;
			}
			else
			{
				read_out(get_first);		//display the information about the first one in the list to the user
				time_use = cal_time();		//ask user to type leave time, and count it to a total minutes for statistic record.
				if(!hello.remove_person(time_use))	//use remove function in service, pass the total minutes in as well. 
				{
					cout<<"The customers' list is empty. " <<endl;
				}	
			}
		}
		else if(choice == 3)				//find out there are people in line or not
		{
			if(!hello.find_out_person(get_first))	//use node_q get_first to get the information of the first node of queue at the same time.
			{
				cout<<"There is no people in the line. "<<endl;
			}
			else
			{
				read_out(get_first);		//print out the information 
			}
		}
		else if(choice == 4)				//find out there is a record on the top of the stack or not.
		{
			if(!hello.find_out_statistic(get_top))	//use stat get_top struct to get the record at the same time.
			{
				cout<<"There is no statistic result. "<<endl;
			}
			else
			{
				read_out_stat(get_top);		//print out the record(latest)
			}
		}
		else
		{
			menu = -1; //exit
		}
	}
	deleter(add);		//deallocate the node_q add, get_first
	deleter(get_first);	
}

//this function is for creating a new customer informatiom and storing it in the node_q
//input:: node_q
//output:: node_q with new information
void create(node_q * & add)
{
	char tempArray[30];

	if(add->name)			//check add node_q is not empty before deleting it
		delete [] add->name;
	if(add->order)
		delete [] add->order;
	cout<<"What's the customer's name ? : ";	//ask users to type in information
	cin.get(tempArray,30,'\n');		
	cin.ignore(100,'\n');
	add->name = new char[strlen(tempArray)+1];
	strcpy(add->name, tempArray);			//store the information in the add node_q
	cout<<endl;
	cout<<"What's the order ? : "; 
	cin.get(tempArray,30,'\n');
	cin.ignore(100,'\n');
	add->order = new char[strlen(tempArray)+1];
	strcpy(add->order, tempArray);
	cout<<endl;
	cout<<"the arrival time of the customer "<<endl;
	cout<<"Please type the hour of time first (24 hour system): ";
	cin>> add->arrival_h;
	cin.ignore(100,'\n');
	cout<<"Please type the minutes of time : ";
	cin>> add->arrival_m;
	cin.ignore(100,'\n');
	cout<< "The arrival time is: " << add->arrival_h << ":"<< add->arrival_m<<endl;
	
}
//this function is for counting the total minutes of leave time.
//output::the total minutes number of leave time
int cal_time()
{
	int hour;	//store hour of the time
	int min;	//store minutes of the time
	cout<<"the leave time of the customer "<<endl;		//ask the user to type in the time first
	cout<<"Please type the hour of time first (24 hour system): ";
	cin>>hour;
	cin.ignore(100,'\n');
	cout<<"Please type the minutes of time : "; 
	cin>>min;
	cin.ignore(100,'\n');
	
	return (hour*60+min); //return the total minutes after counting. 


}
//this function is for deallocating the node_q
//input::a node_q pointer
void deleter(node_q * & add)
{
	if(add->name)			//check whether a dynamic array is empty or not before deleting it
		delete [] add->name;
	if(add->order)
		delete [] add->order;
	delete add;	
}
//display the first customer information currently 
//input::a node_q pointer
//output:: print out the information of the node_q
void read_out(node_q* get_first)
{
	cout<< "Name : "<< get_first->name <<endl;
	cout <<"Order : " << get_first->order <<endl;
	cout<< "The arrival time is : " << get_first->arrival_h<< ":"<< get_first->arrival_m<<endl;
	
}
//display the top statistic record currently
//input::a stat struct 
//output:: print out the record of the struct.
void read_out_stat(stat get_top)
{
	cout<<"-----------------------"<<endl;	
	cout<<"The worst wait time : " << get_top.wait_time <<endl;
	cout<<"Average time : " << get_top.average_time <<endl;
	cout<<"-----------------------" <<endl;
}
//for displaying the menu
//output:: print out the menu content
void output_menu()
{
	cout << "------------------------------------------"<<endl;
	cout << "1. Add a new customer " << endl;
	cout << "2. remove the first customer currently " << endl;
	cout << "3. check whether there are people in the line. " << endl;
	cout << "4. check the statistic result currently. " << endl;
	cout << "5. exit : " <<endl;
	cout << "-------------------------------------------"<<endl;
}













