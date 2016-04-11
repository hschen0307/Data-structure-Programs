#include "app_entry.h"

//This file declares the all the content of the table class. it includes two struct type, 
//class table's all functions' prototypes, and class table's private members.

//declare a node type struct, this struct is for founding a linear link list which is out of the hash table.
struct node
{
       app_entry entry; //for storing data in app_entry class.
       node * next;	
};
//declare a h_node type struct, this struct is for founding a hash table using chains.
struct h_node
{
       app_entry *entry;	//for pointing data of the linear link list.
       h_node * next; 		
};
//declare the table class
class table
{
      public:
	     //prototypes	
             table(int size=23);    	//constructor, input size for initializing the hash table
             ~table();			//destructor
             int insert(char * key_value);  //add keywords to the linear link list and the hash table.
             int retrieve(char * title_to_find, app_entry * & apps_list, int key_count) const;   //find apps based a keyword.
             int hash_function(char* keyword)const; 	//to count which chain to put the information based on the keyword.  
             int main_data(const app_entry & to_add);	//to store and add information in the linear link list.      
	     int count_keyword(char* keyword)const; 	//to count how many apps is in the table with the keyword.
	     int display(app_entry* apps_list, int count_key)const;		
	     int display_linear(); 			//display the linear link list's all content.
             int display_all()const; 			//display the hash table's all content.
      private:
	      //private members
	      node* head;				//the head of the linear link list
              h_node ** hash_table; 			//the head of ench chains of the hash table
	      int hash_table_size;			//the hash table size 
};
