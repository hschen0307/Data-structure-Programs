#include "graph.h"
using namespace std;
//Student: Hsuan-Chih, Chen
//date: 06/08/2015
//This file offer users to build a graph, display all possible tasks that can happen once a task is completed, and display all tasks.
//protoypes
void add_task(table & my_task,int size); //combine all adding steps in one function.
void connect_task(table & my_task); //combine all connecting steps in one function.
void display(table & my_task);	//display all vertices that are adjancent to a given vertex.
void display_all(table & my_task); //diplay all tasks in a gragh by using depth first traversal.
int main()
{
    int size = 0;	//for storing how many tasks users want to add in.
    cout <<"How many tasks you want to add: "; //let user decide how many tasks ,then create the adjacency list with that size.
    cin >> size; cin.ignore(100,'\n');    
    table my_task(size);
    //add tasks to the adjacency first  
    add_task(my_task,size);
    //add connections
    connect_task(my_task);
    //Ddisplay all vertices that are adjancent to a given vertex.
    display(my_task);     
    //display tasks in a gragh by using depth first traversal.
    display_all(my_task);
    return 0;
}
//combine all adding steps in one function.
//input::none
//output::none
void add_task(table & my_task,int size)
{
    task to_add;	//store the information of a task which a user types in.
    char option = '0';  //store the choice from users 
    char title[100];	//static array store the task title temporarily
    char* task = NULL;	//pointer, create a dynamic array  to store the task title
    char* des = NULL;	//pointer, create a dynamic array to store the task description
    char description[100]; //static array store the description temporarily
    int count = 0;
    	
    do
    {
       cout <<"Please enter a task: ";			//users type in
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the description: ";
       cin.get(description, 100); cin.ignore(100,'\n');
       task = new char[strlen(title)]; strcpy(task,title);	//create a dynamic array  to store the task title
       des = new char[strlen(description)]; strcpy(des,description);	//create a dynamic array to store the task description
       if(!to_add.create_entry(task, des))	//call create_entry function of the task class, for adding all information to the object to_add 
       {
		cout<<"adding error, Please add it again."<<endl; 
       }
       if(!my_task.insert_vertex(to_add)) //insert it into the adjancent list 
       {
		cout<<"adding error, Please add it again."<<endl;
       }
       if(task)		//delete the dynamic arrays
       {
       	    delete [] task;
       }
       if(des)
       {
           delete [] des; 
       }	
       ++count;
       if(count<size)
       {
       		cout <<"continue to add or not ( y / n ) ";	//add the next task
       		cin >> option; cin.ignore(100,'\n');
       }
       else
       {
		cout <<"You already type in all tasks."<<endl;
		option = -1;
       }
    }while (option == 'y');
}
//combine all connecting steps in one function.
//input::none
//output::none
void connect_task(table & my_task)
{
    char option = '0'; //store the choice from users
    char title[100]; //static array store the task title temporarily
    char connected[100]; //static array store the connected task temporarily
    char* task = NULL;	//pointer, create a dynamic array  to store a task title
    char* connect = NULL; //pointer, create a dynamic array to store a connected task 
    do
    {
       cout<<"==Connect tasks==" <<endl;
       cout <<"Enter a task first : "<<endl;
       cin.get(title, 100); cin.ignore(100,'\n');
       task = new char[strlen(title)]; strcpy(task,title);	//create a dynamic array to store a task title
       cout <<"Enter a task to be the next task : "<<endl;
       cin.get(connected, 100); cin.ignore(100,'\n');		//create a dynamic array to store a connected task
       connect = new char[strlen(connected)]; strcpy(connect,connected);
       if(!my_task.insert_edge(task, connect)) //insert a connected task to a edge list. 
       {
		cout<<"Wrong task title. Please connect it again."<<endl;
       }
       if(task)	//delete the dynamic arrays
       {
       	    delete [] task;
       }
       if(connect)
       {
           delete [] connect; 
       }
       cout <<"continue to connect or not ( y / n ) ";
       cin >> option; cin.ignore(100,'\n');
    } while (option == 'y');
}
//display all vertices that are adjancent to a given vertex.
//input::none
//output::none
void display(table & my_task)
{
    char option = '0'; //store the choice from users
    char title[100];   //static array store the task title temporarily
    char* task = NULL; //pointer, create a dynamic array to store a task title

    do
    {
       cout <<"Enter task to display: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       task = new char[strlen(title)]; strcpy(task,title); // create a dynamic array  to store a task title
       cout<<" You can do these task(s) once this task is completed : " <<endl; 
       if(!my_task.display_adjacent(title))	//display a specific edge list in a graph
       {
	   cout<<"title is wrong."<<endl;
       }
       if(task)	//delete the dynamic array
       {
       	    delete [] task;
       }
       cout <<"continue to connect or not ( y / n ) ";
       cin >> option; cin.ignore(100,'\n');
    } while (option == 'y');
}
//diplay all tasks in a gragh by using depth first traversal.
//input::none
//output::none
void display_all(table & my_task)
{
    char option = '0'; //store the choice from users
    do
    {
       if(!my_task.display_all())	//display all tasks in all edge lists
       {
           cout<<"display error."<<endl;
       }
       cout <<"continue to connect or not ( y / n ) ";
       cin >> option; cin.ignore(100,'\n');
    } while (option == 'y');

}
