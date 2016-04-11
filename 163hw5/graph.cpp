#include "graph.h"
using namespace std;
//Student: Hsuan-Chih, Chen
//This file defines all functions in the table class.
//constructor
//inicialize all private members
table::table(int size)
{
      //Allocate the adjacency list 
      list_size = size;
      adjacency_list = new vertex[list_size];	
      for(int i=0;i<list_size;++i)
      {
            adjacency_list[i].entry = NULL; //set entry pointer to NULL
            adjacency_list[i].head = NULL;  //set head pointer to NULL
	    adjacency_list[i].flag = 0;	    //set flag to zero	
      }
}
//destructor
//deallocate all dynamic memory
table::~table()
{
	for(int i=0; i<list_size; ++i)
	{
		node* current = adjacency_list[i].head;	//delete all edge lists
		node* temp = NULL;
		while(current)
		{
			temp = current;
			current = current->next;
			temp->adjacent = NULL;
			delete temp;
		}
	}
	for(int i=0; i<list_size; ++i)	//delete all information in each vertex 
	{
		if(adjacency_list[i].entry)
		{
			delete adjacency_list[i].entry;
		}
	}
	delete [] adjacency_list;    //delete the adjacency_list
}
//Store the vertex at a positon of an adjacency list
//input:: a task object with a task information
//output:: success,1. fail,0.
int table::insert_vertex(const task & to_add)
{
        for(int i=0; i<list_size;++i)	//using for loop to check every position in a adjacency list.
        {
            if(adjacency_list[i].entry == NULL)	//if a position haven't had data, then put a new task to the position.
            {
                task* temp;
				temp = new task;
                if(!temp->copy_entry(to_add))
                {
                    return 0;	//copy fail
                }
                adjacency_list[i].entry = temp;
                return 1;		//success
            }
        }
        return 0; //fail, if list is Full.
}
//Attach an edge to a vertex
//input:: two dynamic array(pointers). One is a task title. another is another task we want to attach.
//output::success,1. fail,0.
int table::insert_edge(char * current_vertex, char * to_attach)
{
       int position = 0; //for storing the position number of the task in the adjacency list
       int attach = 0;	 ///for storing the position number of the task we want to attach  in the adjacency list
       position = find_location(current_vertex);	//call find_location function to have a  position number
       if(position == -1)			//fail,if title is not in the adjacency list
       {
			return 0;
       }
       attach = find_location(to_attach);
       if(attach == -1)
       {
			return 0;
       }
       node* temp = new node;		    //add a new node to a edge list of a vertex
       temp->adjacent = & adjacency_list[attach];	//store 'attach vertex' address in the adjacent pointer ofthe node .
       temp->next = adjacency_list[position].head;	//connect
       adjacency_list[position].head = temp;	
       return 1;		//add successfully
}
//Display all vertices adjacent to the one specified
//input:: a dynamic array with a title of a vertex
//output:: success,1. fail,0.
int table::display_adjacent(char * key_value)
{
    int position = 0;	//store the vertex number in the adjacency list
    position = find_location(key_value);	//call find_location function
    if(position == -1)
    {
	return 0;	//fail, wrong title
    }
    display_adjacent(adjacency_list[position].head); //call the recursively function to display every node in a edge list.
    return 1; 		//success
}
//Recursively function to display every node in a edge list.
//input:: A node pointer
//output::none
void table::display_adjacent(node* start)
{
	if(!start)
	{
		return;
	}
	else
	{
		start->adjacent->entry->display();	//call display function in task class to display all information of a task.
		display_adjacent(start->next);		//traverse to the next node
	}
	
}
//Display all task in a graph by using depth first traversal
//input::none
//output:: 1, success
int table::display_all(void)
{
	
	for(int i=0;i<list_size;++i)
	{
		if(adjacency_list[i].flag == 0)	//if the vertex haven't displayed(flag = 0), then display it and set its flag to be 1.
		{
		   adjacency_list[i].entry->display();	//call task class's display function
		   adjacency_list[i].flag = 1;
		}
    		display_all(adjacency_list[i].head);	//call the recursively function to display every node in all edge lists.
	}
	reset_all_flag();	//set all flags to be zero.
	return 1;	//success
}
//Recursively function to display every node in all edge lists.
//input::A node pointer
//output::none
void table::display_all(node* start)
{
	if(!start)
	{
		return;
	}	
	if(start->adjacent->flag==0)	//if the vertex haven't displayed(flag = 0), then display it and set its flag to be 1.
	{
		start->adjacent->entry->display();
		start->adjacent->flag = 1;
		display_all(start->adjacent->head);	//for depth first traversal, directly go to another eage list first.
	}
	display_all(start->next);			//if the node already display, then go to the next node in the same edge list. 
}
//Find a location in the adjacency list
//input:: a dynmaic array(pointer) with a title
//output:: a location number(i) or -1, no matching title
int table::find_location(char * key_value)
{ 
      for(int i=0; i<list_size;++i)		//use for loop to check every vertex
      {
            if(adjacency_list[i].entry != NULL)	//if the vertex is not empty
            {
                if(adjacency_list[i].entry->compare(key_value))	//compare the title of the vertex with key title.
                {
                    return i;	//get a match, return this location number.
                }
            }
      }
      return -1;	//fail,no matching title
}
//Set all flags in every vertex is zero for reusing display all function.
//input::none
//output:none
void table::reset_all_flag()
{
      for(int i=0; i<list_size;++i)	//use for loop to check every vertex
      {
           	adjacency_list[i].flag = 0;	//set every flag to be zero
      }
}
