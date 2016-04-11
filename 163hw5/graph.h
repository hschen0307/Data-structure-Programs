#include "task.h"
//Student: Hsuan-Chih, Chen
//This file declares two structs types and contents. All functions and private membersof the table class. 
//struct vertex 
struct vertex
{
       task * entry;        //for storing a task's information
       struct node * head;  //a pointer, to an edge list 
       int flag;	    //flag, to recognize a vertex is displayed or not.
};
//struct node
struct node
{
       vertex * adjacent;	//for pointer a vertex                        
       node * next;		//for traversing to the next node
};
//class table
class table
{
      //prototypes
      public:
             table(int size);     //constructor
	     ~table(void);	    //destructor
             int insert_vertex(const task & to_add); //Store the vertex at a positon of an adjacency list
             int find_location(char * key_value); //Find a location in the adjacency list            
             int insert_edge(char * current_vertex, char * to_attach); //Attach an edge to a vertex
             int display_adjacent(char * key_value); //Display all vertices adjacent to the one specified
	     void reset_all_flag();  ///Set all flags in every vertex is zero for reusing display all function.
             int display_all(void); //Display all task in a graph by using depth first traversal
      private:
	      void display_adjacent(node* start);//Recursively function to display every node in a edge list.
	      void display_all(node* start);	//Recursively function to display every node in all edge lists.
              vertex * adjacency_list; //create a adjacency list dynamically
	      int list_size;	       //store the list size
};
