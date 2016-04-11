#include<cstring>
#include<cctype>
#include<iostream>
#include<fstream>

//diy.h file
//Firstly, I declare two struct types and their contents in this file. 
//Secondly,I declare a class called 'diy', its function prototypes of public section, and its private members in this file.
//Thirdly, I include the libraries which I use in this program in this file.

//This struct can store specific information of a item.
struct part
{	
	int partNum;		//the variable can store part number of a item.
	char* description;	//the pointer can point to a dynamic array to store the description of the item.
	int quantity;		//the variable can store the quantity of the item.
	int totalSteps;		//the variable can store the total number of the steps which the item use.
	int *stepsList;		//the pointer can point to a dynamic array to make a list for the specific steps(step) which the item use.
	int stepNum;		//the varible can store each item step number.(for sorting by step number)
};

//This struct can produce nodes for building a linear link list.
//We also can put every data of part struct in every node for traversing and sorting easily.
struct node
{
	part data;	//the part object can put all informain of a item in a node.
	node * next;	//the pointer can store where the next node is for building a linear link list.

};

//Firstly, I can build my ADT by creating some functions in this class and put the final results in the constrctor of this class.
//Secondly,I also set all functions for displaying in this class.
//Thirdly, I set two head(partHead and stepHead) pointers of two sorted linear link lists in the private section of this class for storing the two heads' addresses.
class diy
{
    public:
	   //functions prototypes
	   diy();	//the function is contructor. It load the parts and build the two LLLs.
	   ~diy();	//the function is destructor 
	   int displayParts();		//the function can display a sorted linear link list by part number.
	   int displaySteps();		//the function can display a sorted linear link list by step number.
	   void sortPart(node * temp);	//the function can build a new linear link list and sort it by part number at the same time.
	   void sortStep(node *  temp);	//the function can build a new linear link list and sort it by step number at the same time.
	   void readFile();		//the function can read all the information from .txt immediately store the information in a struct. 
	   int nextStep(int stepNumber);	//the function can find the specific items of one step.
    
    private:	
	   //private members
	   node * partHead;	//the pointer can store a address of a head node in  a linear link list sored by part number.
	   node * stepHead;	//the pointer can store a address of a head node in  a linear link list sored by step number.
};

