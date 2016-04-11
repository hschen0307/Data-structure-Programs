#include "diy.h"
using namespace std;
//diy.cpp
//all functions of the 'diy' class are defined in this class. 

//the function is the contructor.
//To initialize all private members in this class.
//the function is contructor. It load the parts and build the two LLLs. 
diy::diy()
{
	
	partHead = NULL; 
	stepHead = NULL;
	readFile(); //the function call is for loading our ADT in the constructor.
}

//the function is destructor for deallocate all dynamically allocated memory.
diy::~diy()
{
	node * current;
	while(partHead !=  NULL)
	{
		current = partHead -> next;
		delete [] partHead -> data.description; 
		delete [] partHead -> data.stepsList;
		delete partHead;
		partHead = current;
	}	
	while(stepHead !=  NULL)
	{
		current = stepHead -> next;
		delete [] stepHead -> data.description; 
		delete [] stepHead -> data.stepsList;
		delete stepHead;
		stepHead = current;
	}
}

//the function can read all the information from .txt and immediately store the information in a struct.
//in this function I have a temp struct of part for storing a item information temporarily.
// My way is to catch one item information, and then copy it in a new node. 
//And then put the new node in a linear link list and sort it right away. 
void diy::readFile()
{

	int steps = 0;	//the variable can store the total step number. just for use conveniently 
	node* temp;	//the pointer can point to a node which store all data of a item temporarily from .txt file.
	char tempArray[30];	//the variable can store the description array data temporarily for copying to a dynamical array.
	temp = new node;	//the node can store all data of a item temporarily.
	ifstream fileIn;	//the variable is for geting information from .txt file.
	fileIn.open("parts.txt");	
	if(fileIn)
	{	
	
		fileIn >> temp->data.partNum; //it is sort of a trigger before using .eof() function. It's neccessary that we need to read the file first.
		fileIn.ignore(100,':');
		while(!fileIn.eof())
		{
			//get every single data and store them in the temp struct  
	                fileIn.get(tempArray, 30,':');	
        			fileIn.ignore(100,':');
        			temp->data.description = new char[strlen(tempArray)+1];	//a dynamical array  store a description
        			strcpy(temp->data.description, tempArray);
                	fileIn >> temp->data.quantity;
                	fileIn.ignore(100,':');
                	fileIn >> temp->data.totalSteps;
                	fileIn.ignore(100,':');
                	steps = temp->data.totalSteps;
                	temp->data.stepsList = new int[steps];	//a dynamical array store specific steps of each items. Because total steps of each item are different.  
			for(int i = 0; i<steps-1; ++i)
                	{
                        	fileIn >> temp->data.stepsList[i];
                        	fileIn.ignore(100,':');
                	}
			fileIn >> temp->data.stepsList[steps-1]; //Because in .txt there is a '\n' behind the last step different from other steps, I manage it singly.
                	fileIn.ignore(100,'\n');

			sortPart(temp);		//I directly call the sortPart function to copy temporary data to another new node of the sortPart function, and build a sorted linear link list by part in sortPart function. 
			sortStep(temp);		//I directly call the sortStep function to copy temporary data to another new node of the sortStep function, and build a sorted linear link list by step in sortPart function.		

			fileIn >> temp->data.partNum;	//it can get the next one item's first information
			fileIn.ignore(100,':');
		}
		
	}

}


//This function can copy the data from the temp struct to a new node, 
//add  the new node to the sorted linear link list by part number and sort it at the same time.
void diy::sortPart(node* temp)
{
	node * curSort;		//this pointer is for traversing.	
	node * previous;	//this pointer is for memorizing the node ahead of the last node
	node * temp2;		//this pointer is for inserting.  
	
		node * newNode = new node;	//create a new node 
		newNode->data = temp-> data;	//copy data from temp struct which passes in.
		
		//add the new node to a linear link list and sort it by part number at the same time.
		//sort by part nmber section
		if(partHead == NULL)	//for the first new node, if list is empty.
		{
			partHead = newNode;
			partHead -> next = NULL;

		}
		else if(newNode->data.partNum < partHead->data.partNum)	//if new node's part number is smaller than the head node's part number, add it in the beginning and set it to be head. 
		{
			newNode->next = partHead;
			partHead = newNode;
		}
		else
		{
			
			curSort = partHead;
			while(curSort->next != NULL && curSort->data.partNum < newNode->data.partNum) //keep traversing if new node's part number is smaller than current's part number.
			{			
				previous = curSort;
                                curSort = curSort -> next;
			}
			if(curSort->next == NULL) //if current's node is the last one. 
			{		
				if(curSort->data.partNum < newNode->data.partNum) //add new node in the end
				{
					curSort->next = newNode;
					newNode->next = NULL;
				}
				else
				{
					previous->next = newNode;	//add new node ahead of the last node
                                	newNode->next = curSort;
				}
				
			}
			else
			{
				temp2 = curSort->next;		//in other case, directly insert new node behind the current node.
				curSort->next = newNode;
				newNode->next = temp2;
				
			}
		}
			
			
}

//This function can copy the data from the temp struct to a new node, 
//add the new node to the sorted linear link list by step number and sort it at the same time.
void diy::sortStep(node*  temp)
{
	
	node * curSort;		//this pointer is for traversing.	
	node * previous;	//this pointer is for memorizing the node ahead of the last node
	node * temp2;		//this pointer is for inserting.

	
	//this for loop is for creating how many new nodes of a item for different steps.
	//create one and sort one in the linear link list every time.
	for(int i=0; i < temp->data.totalSteps;++i)
	{
		
		node * newNode = new node;
		newNode->data = temp-> data;
		newNode->data.stepNum = temp->data.stepsList[i]; //copy one step number of steps from step list to this new node
		
		//sort section
		//almost same as by part number's sort section						 
		if(stepHead == NULL)
		{
			stepHead = newNode;
			stepHead -> next = NULL;

		}
		else if(newNode->data.stepNum < stepHead->data.stepNum)
		{
			newNode->next = stepHead;
			stepHead = newNode;
		}
		else
		{
		
			curSort = stepHead;
			while(curSort->next != NULL && (curSort->data.stepNum < newNode->data.stepNum || curSort->data.stepNum == curSort->next->data.stepNum)) //if it bump into same step number node it will keep traversing
			{			
				previous = curSort;
                                curSort = curSort -> next;
			}
			if(curSort->next == NULL)
			{		
				if(curSort->data.stepNum < newNode->data.stepNum)
				{
					curSort->next = newNode;
					newNode->next = NULL;
				}
				else
				{
					previous->next = newNode;
                                	newNode->next = curSort;
				}
				
			}
			else
			{
				temp2 = curSort->next;
				curSort->next = newNode;
				newNode->next = temp2;
				
			}
		}
		

	
	
				
	}
	

}


//This function is for displaying all node's data of sorted linear link list by part number
int diy::displayParts()
{
	node* current; //the pointer is for traversing
	
	current = partHead;
	while(current != NULL)
	{
		//output information of each node's data
		cout << "part num : " << current->data.partNum << endl;
       		cout << "description : " << current->data.description << endl;
        	cout << "quantity : " << current->data.quantity <<endl;
        	cout << "totalSteps : " << current->data.totalSteps <<endl;
		cout << "stepList : ";
		for(int j = 0 ; j < current->data.totalSteps; ++j)
		{
        		cout << current->data.stepsList[j] << ',' ;

		}
		cout << endl;
		cout << " ------------------" <<endl;
		current = current -> next;		
	}	

}

//This funtion is for displaying all node's data of sorted linear link list by step number
int diy::displaySteps()
{
	node* current;	//the pointer is for traversing
	
	current = stepHead;
	while(current != NULL)
	{
		
		//output information of each node's data
		cout << "step number : " << current->data.stepNum << endl;
		cout << endl;
		cout << "part number : " << current->data.partNum << endl;
       		cout << "description : " << current->data.description << endl;
        	cout << "quantity : " << current->data.quantity <<endl;
        	cout << "total Steps : " << current->data.totalSteps <<endl;
		cout << endl;
		cout << " ------------------" <<endl;
		current = current -> next;		
	}


}




//the function can find the specific items of one step and display their information.
int diy::nextStep(int stepNumber)
{


	node* current;	//the pointer is for traversing
	
	current = stepHead;
	
	while(current != NULL && current->data.stepNum <= stepNumber)
	{
		if(current->data.stepNum == stepNumber)
		{	
			//output information of each node's data
			cout << "step number : " << current->data.stepNum << endl;
			cout << "part number : " << current->data.partNum << endl;
       			cout << "description : " << current->data.description << endl;
        		cout << "quantity : " << current->data.quantity <<endl;
        		cout << "total Steps : " << current->data.totalSteps <<endl;
			cout << "step list : ";
			
			for(int j = 0 ; j < current->data.totalSteps; ++j)
			{
        			cout << current->data.stepsList[j] << ',' ;

			}
			cout << endl;
			cout << " ------------------" <<endl;
		
		}
		current = current->next;
		
	}


	return 0;

}
