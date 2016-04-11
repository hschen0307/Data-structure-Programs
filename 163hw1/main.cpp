#include "diy.h"
using namespace std;

//Hsuan-Chih, Chen. 2015/04/15. CS163. PROGRAM 1.
//This program can arrange and sort all items from a .txt file to be two sorted linear link list. One is by part number. Another one is by step number. Finally, a user can choose to display all items list sorted by part number, all items list soted by step number, or all items of a specific step.   	

//maip.cpp file
//Firstly, I just set a function,main function, in my main.cpp file. it makes a object of a class called 'diy' for using functions in the 'diy' class.
//Secondly, I set a menu in this file to let users use this program easily.  

//This function makes a menu for users, makes a object called 'hello' for using the functions of 'diy' class, and prompts user to type in step number for finding items of a specific step.   
int main()
{
	diy hello;		//the object can let us use the fuctions of the 'diy' class.  
	int step;		//the variable can store a step number which a user type in. 
	int reBack;		//the variable can store a return value from the nextStep function.
	int control=0;		//the variable can keep the menu working untill a user type exit option. 
	int menu;		//the variable can store a number of a option which a user type in.
	
	//menu
	while(control == 0)
	{	
		cout << endl;
		cout << "1. display all the items by the part number"  << endl;
		cout << "2. display all the items by the step number"  << endl;
		cout << "3. display items of a step"  << endl;
		cout << "4. exit "  << endl;
		cout << "Which option do you wanna choose : " ;
		cin >> menu;
		cin.ignore(100,'\n');
		
		if( menu == 1)			//option 1
		{
			hello.displayParts();	

		}
		else if( menu == 2)		//option 2 
		{
			hello.displaySteps();
		}
		else if( menu == 3)		//option 3
		{
			cout << "which step do you want to see : " ;
			cin >> step;
			cin.ignore(100,'\n');
			reBack = hello.nextStep(step);

		}
		else			//exit
		{
			control = -1;
		}
		cout << endl;
	}
}    
