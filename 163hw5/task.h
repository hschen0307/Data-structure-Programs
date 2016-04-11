#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
//Student: Hsuan-Chih, Chen
//This file declares all functions and private member in the task class.
//task class
//This task entry supports a task title and description
class task
{
      //prototypes
      public:
             task(void);	//construtor
             ~task(void);	//destructor
             int create_entry(char * title, char * des); //This function is for creating a new entry object which stores information from a user types in.
             int copy_entry(const task & copy_from);//This function is for copying all information from a entry object
             bool compare (char * is_it_a_match); //This function is for searching a matching title
             void display(void) const; //this function is for display all information of a node.
      //private member
      private:
              char * task_title; //store title of a task
              char * description;//store description of a task
};
