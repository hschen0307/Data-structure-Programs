#include "table.h"
using namespace std;
//this file defines all the functions in the table class.  
//constructor
//input::hash table's size
//initialize the hash table size and make all head of chain to be NULL.
table::table()
{
	root = NULL;
}
//destructor
//deallocate all dynamic memory.
table::~table()
{	
}

//This function is for inserting a node to the hash table. The node has a pointer(h_node) which points to the data of the linear link list.
//input::an dynamic array of a keyword for hashing
//output:::return 1 when adding successfully, return 0 when adding unsucessfully.
int table::add(char * key_value, app_entry & to_add )
{	
	int num = 0;
	if(!first)
	{
		if(!(*first).copy_entry(to_add))
		{
			//delete [] app_entry;
			return 0;	
		}

	}
	num = hash_function(key_value);
        if(num==-1)			//if hashing fails, delete temp and return 0.
	{
	    return 0;
	}	
	if(!insert(root,num))
	{
		return 0;
	}
        return 1;				//success, return 1.
}
int table::insert(t_node*&root, int num)
{
	if(!root)
	{
		root = new t_node;
		root->entry = first;
		root->key_num = num; 
		root->left = NULL;
		root->right = NULL;

		return 1;
	}
	else if(root-> key_num > num)
	{
		return insert(root->left,num);
	} 
	else
	{
		return insert(root->right,num);
	}
	
}

int table::let_first_null()
{
	first=NULL;
}
//This function can count how many apps matches the keyword. So I can know how big a dynamic array of apps I need to pass in the ADT for geting them.
//input::an dynamic array of a keyword.
//output:: if success, it will return a total number of apps. if unsucess, it will return 0.
/*
int table::count_keyword(char* keyword)const
{
	h_node * current=NULL;	   //pointer, for tarversal.
	int position = 0;	   //int variable, for storing position from hash fuction returning.
	int count = 0;		   //int variable, for counting how many keywords get matching.
	if(!keyword)		   //if keyword is NULL, return 0.
	{
		return 0;
	}
	position = hash_function(keyword);//get a position(a head of a chain)of the keyword from the hash function
	if(position==-1)	 	 //if hashing fails, return 0.
	{		
	    return 0;
	}	
	current = hash_table[position]; //traverse the chain 
        while(current != NULL)
        {
            if((*current->entry).count_key(keyword))	//call app_entry count_key function for searching every keywords in a node.
	    {
               ++count;     				//get match, count plus 1.
	    }		
            current = current->next;		
        }
	return count;				       //return the final count number
}
//This function can find apps based on keyword,and then copy the apps' information to a apps_list passed in, and then send it back to the main function.
//input::an dynamic array of a keyword, a app_entry type of a dynamic list, and a int variable with the total number of apps based on a keywords.
//output:: Return 1 when finding and copying all information successfully. Return 0 when it is unsuccessful.
int table::retrieve(char * key_to_find, app_entry *& apps_list,int key_count) const
{
        h_node*current = NULL;	//pointer, for traversal.
	app_entry found;	//a app_entry, for copying the information back from the app_entry's retrieve function.
	int position = 0;	//int variable, for storing position from hash fuction returning.
	int counter = 0;	//int variable, for stop searching when the apps_list is full.
	if(key_count == 0)	//no match keyword, return 0.
	{
		return 0;
	}
	if(!key_to_find)	//a keyword is nothing.
	{
		return 0;
	}
	position= hash_function(key_to_find);	//get a position(a head of a chain)of the keyword from the hash function
        current = hash_table[position];		//traverse the chain
        while(current != NULL && counter < key_count)	//keep traversing when the app_list is not full, there is not the end of the list.
        {
            	if((*current->entry).retrieve(key_to_find, found))	//dereference a pointer in a node and use the retrieve fun of the app_entry class. 
		{
			if(!apps_list[counter].copy_entry(found))	//using counter to access right position in apps_list, and copy information in it.
			{
				return 0;
			}
			++counter;		      			//count the app_list current position for storing.
		}
		current = current->next;
        }
        return 1;							//success, return 1.
}
//this function is for hashing up to the keyword's sum of ASCII codes.
//input::an dynamic array of a keyword
//output::a number of hash table position, or -1 when keyword is NULL.
*/
int table::hash_function(char * keyword)const
{
    int counter = 0;	//for counting the sum 
    int len = 0;	//for storing the number of all letters of a keyword.
    if(!keyword)
    {
	return -1;
    }	 		
    len = strlen(keyword);	//get the the number of all letters of a keyword
    for(int i=0; i<len;++i)	//for counting the sum of ASCII codes.
    {
	counter += *(keyword+i);
    }
    return counter;				//return a position number of the hash table
}
//this function is for displaying a app_entry type dynamic array 
//input::a app_entry type dynamic array.
//output::1, when display successfully. 0, when display unsuccessfully.
/*
int table::display(app_entry* apps_list, int count_key)const
{
	cout<<"--------------------------"<<endl;
	for(int i=0; i< count_key;++i)
	{
		if(!apps_list[i].display())
		{
			return 0;
		}
	}
	cout<<"--------------------------- "<<endl;	
	return 1;
}
//this function can display the linear link list where I store the data.
//input::no input
//output:: 0, when the list is empty or error of displaying in app_entry class. 1, when the display success. 
int table::display_linear()
{
	if(!head)		//when list is empty. return 0
	{
	    return 0;
	}	
	node* current = head;	//traversal
	while(current != NULL)
	{	
		cout << "---------------------------" <<endl;
		if(!current->entry.display())	//call the display function of the app_entry class.if it fails, return 0.
		{
			return 0;
		}
		current = current->next;
		cout << "---------------------------" <<endl;
	}
	return 1;	
}
*/
//this function can display all information of chains' nodes in the hash table.
//input::no input
//output:: 0, when the list is empty or display error. 1, when display is successful.
int table::display_all()const
{
	if(!display_all(root))
	{
		return 0;
	}
	return 1;
}

int table::display_all(t_node * root)const
{	
	if(root)
	{	
		display_all(root->left);

		if((*root->entry).display())
		{
			return 0;
		}
		display_all(root->right);
		return 1;
	}
}







