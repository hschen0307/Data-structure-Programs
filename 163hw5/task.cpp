#include "task.h"
//Student: Hsuan-Chih, Chen
//This file define all public functions of class task.
//construtor
//initialize all private members in this class.
task::task(void)
{
	task_title = NULL;	//let all pointers point to NULL
	description = NULL;
}
//destructor
//deallocate all dynamic memory.
task::~task(void)
{
	if(task_title)	//check the memoy first before delete it
	{
		delete [] task_title;	//delete the dynamic memory
	}
	if(description)
	{
		delete [] description;	//delete description
	}	
}
//This function is for creating a new entry object which stores information from a user types in. 
//intput:: a task title,a description.
//output:: 1, when creating a object successfully. 0, unsuccessully.
int task::create_entry(char* title, char* des)
{
	if(!title || !des)	//check whether arrays are empty. if one of them is empty, it will directly return 0. 
	{
		return 0;
	}
	if(task_title)
	{
		delete [] task_title;
	}
	if(description)
	{
		delete [] description;
	}
	task_title = new char[strlen(title)];	//create a new dynamic array. The size is up to the name just passed in. 
	description = new char[strlen(des)];	
	strcpy(task_title,title);			//copy the title to the object's task title.
	strcpy(description, des);	//copy the description
	return 1;			//success 
}
//This function is for copying all information from a entry object
//input::task type of a object
//output:: 1,success. 0, unsuccess.
int task::copy_entry(const task & copy_from)
{    
       if(task_title) 			//check whether private members are empty. If they are not empty, delete all the content first.
       	  delete [] task_title;		
       if(description)
	  delete [] description;	
      					
       if(copy_from.task_title==NULL || copy_from.description ==NULL)//if the data of copy soruce is empty, return 0. 
       {
           return 0;
       } 

       task_title = new char[strlen(copy_from.task_title)];		//copy all the information from copy_from to the private memebers in this object.
       description = new char[strlen(copy_from.description)];
       strcpy(task_title, copy_from.task_title); 
       strcpy(description, copy_from.description); 
       return 1; 						//success
}
//This function is for searching a matching title
//input: a task title
//output:: 1, get a match. 0, there is no match.
bool task::compare(char * is_it_a_match)
{
	if(strcmp(is_it_a_match,task_title)== 0)
	{
		return 1;
	}
	return 0;
}
//this function is for display all information of a node.
//input::no
//output::1,when display successfully.
void task::display(void) const		
{	
	cout<<"Task : " << task_title << endl;		//print out all information
	cout<<"description : " << description << endl;
}




















