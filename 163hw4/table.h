#include "app_entry.h"

//This file declares the all the content of the table class. it includes two struct type, 
//class table's all functions' prototypes, and class table's private members.

//declare a node type struct, this struct is for founding a linear link list which is out of the hash table.
//declare a h_node type struct, this struct is for founding a hash table using chains.
struct t_node
{
       app_entry * entry;	//for pointing data of the linear link list.
       t_node * left;
       t_node * right;
       int key_num;	 		
};
//declare the table class
class table
{
      public:
	     //prototypes	
             table();    	//constructor, input size for initializing the hash table
             ~table();			//destructor
             //int retrieve(char * title_to_find, app_entry * & apps_list, int key_count) const;   //find apps based a keyword.
             int hash_function(char* keyword)const; 	//to count which chain to put the information based on the keyword.  
	     //int count_keyword(char* keyword)const; 	//to count how many apps is in the table with the keyword.
	     //int display(app_entry* apps_list, int count_key)const;		
             int display_all()const;
	     int display_all(t_node * root)const;
	     int insert(t_node*&root, int num);
	     int add(char * key_value, app_entry & to_add);  
	     int let_first_null();
			//display the hash table's all content.
      private:
	      //private members
	      app_entry* first;
	      t_node* root;				//the head of the linear link list
};
