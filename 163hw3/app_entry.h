#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
//This file declare all app_entry public functions' prototypes and private members. 
//declare the class app_entry
class app_entry
{
      public:
             app_entry(void);	//constructor
             ~app_entry(void);	//destructor
	     int creat_entry(char* name, char* key[],int all_key, char *des, int rate); //for creating a entry object from input information. 
             int copy_entry(const app_entry & a_new_entry);	//for copying a entry from a entry object(input).
             int retrieve(char * matching_keyword, app_entry & found) const; //for finding matching keyword, and storing all information to a object(input) when getting a match.
             int count_key(char * matching_keyword)const; //for finding matching keyword and return number of a match for counting.
	     //int display_match(char * matching_keyword)const;	 
             int display(void) const;	//for display all information of a node.
      private:
              char * app_name;		//a dynamic array for storing app's name.
              char ** keywords;		//a dynamic array of dynamic arrays for storing keywords in a list.
	      int total_key;		//int variable for storing a total number of keywords.
	      char * description;	//a dynamic array for storing description.
	      int rating;		//int variable for storing rating number.	      				  	
};
