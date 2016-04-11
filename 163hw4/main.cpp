#include "table.h"
//This files is for users to use this program. I do a menu for letting users use it easily.      
void output_menu(); //print out the menu to let user to choose the options 
void read_in_keyword(char*  key_list[],int & count); //let user to type all keywords of a app.
void display_matches(table & haha);//display all apps with a matching keyword
void add_app(table & haha);//to adding a app to the linear link list and hash table.
const int SIZE = 50;//a constant size for reading in words.
int main()
{
	
	
	
	table haha;	//an object of the table type. for using all functions of the table class.
	int option = 0;	//for storing a option from a user.
	int menu = 0;	//the int varible is for entering and exiting the while loop. 
	while(menu == 0)
	{
		output_menu();	//print out the menu
		cin>>option; cin.ignore(100,'\n');
		if(option == 1)
		{
			add_app(haha); 	//for inserting a app to the linear link list and hash table. 
			
		}
		else if(option == 2)
		{	/*
			display_matches(haha);	//display all apps with a keyword(based on a keyword)		*/
		}	
		else if(option == 3)
		{
			/*
			if(!haha.display_linear()) //display all apps in the linear link list 
			{
				cout<< "No apps in the list." <<endl;
			}
			*/
		}                   
		else if(option == 4)
		{
			
			if(!haha.display_all())		//display all apps of chains of hash table. 
			{
				cout<< "No apps in the list." <<endl;
			}
			
		}  
		else
		{
			menu = -1; //exit
		}
  	}
	
}
	
//print out the menu
void output_menu()
{
        cout << "------------------------------------------"<<endl;
        cout << "1. Add a new app. " << endl;
        cout << "2. display matches(based one a keyword)" << endl;
        cout << "3. display all(the linear list)" << endl;
        cout << "4. display all(the table)" <<endl;
	cout << "5. exit" <<endl;
        cout << "-------------------------------------------"<<endl;
}
//read in all keywords
//input:: a statistic  array of dynamic arrays(empty list for storing all keywords), a int variable for counting how many keysword user type in.
//output:: no 
void read_in_keyword(char* key_list[],int & count)
{
	char key[SIZE]; //a statistic array is for storing words tempararily 
	char choice = '0';	//to store a option from a user.
 			
	do
	{	
		cout <<"Please enter the keyword\n";	
		cin.get(key, SIZE, '\n'); cin.ignore(SIZE,'\n');
		key_list[count] = new char[strlen(key)];	//open a new dynamci array to store a keyword
		strcpy(key_list[count],key);			//copy the keyword from key array to the dynamic array.
		++count; 					//for counting total number of keywords a user type in.
		cout << "Do you want to add more keywords(at most 5)?(y/n)\n";
		cin >>choice; cin.ignore(100,'\n');
	}while(choice == 'y' && count < 5);
}
//add the app into the linear link list and table
//input::a object of table type
//ouput::no
void add_app(table & haha)
{
	char name[SIZE];	//a statistic array is for storing words of a name tempararily 
	char *key_list[5];	//a statistic  array of dynamic arrays(for storing all keywords)
	char des[SIZE];		//a statistic array is for storing words of description tempararily 
	int rate = 0;		//a int variable for storing the rating number.
	int count=0;		//a int variable for counting how many keyswords user type in.

	app_entry hello;
	

	cout <<"Please enter the app name\n"; 			//for stoing all information first
	cin.get(name, SIZE, '\n'); cin.ignore(SIZE,'\n');
	read_in_keyword(key_list, count);			//for storing keywords in the list, and get the total number of all keywords 
	cout <<"Please enter the description\n";
	cin.get(des, SIZE, '\n'); cin.ignore(SIZE,'\n');
	cout <<"Please enter the rating \n";
	cin >>rate; cin.ignore(100,'\n');
	if(!hello.creat_entry(name, key_list,count, des, rate))	//for creating a object from all the temperary information of a app.
	{
		cout<<"unsucess adding." <<endl;	
	}
	for(int i=0;i<count;++i)
	{
		if(!haha.add(key_list[i],hello))	//insert based on every keyword of this object(it will creat a pointer node in the table to point the head node 's data of the linear link list every time.
		{
			cout << "insert error" <<endl;
		}
	}
	if(!haha.let_first_null())
	{
		cout << "first_null error"  <<endl;
	}
	for(int i=0;i<count;++i)	//deallocate all the dynamic memory in the key list.
	{
		if(key_list[i])
		{
			delete [] key_list[i];
		}
	}
	
			     
}
/*
//for displaying all apps based on a keyword
//input::a table type object
//output::no
void display_matches(table & haha)
{
	app_entry* apps_list; //a dynamic array of app_entry type. For storing all data back from table.
	char key[SIZE];		//for storing keyword temperarily 
	char* keyword = NULL;	//for storing keyword using dynamic array
	int count_key=0;	//for counting how many apps based on a keyword in the table 
	cout <<"Please enter the keyword\n";	
	cin.get(key, SIZE, '\n'); cin.ignore(SIZE,'\n');
	keyword = new char[strlen(key)];	//create a dynamic array for storing a keyword
	strcpy(keyword,key);
	count_key = haha.count_keyword(keyword);	//using count_keyword function to get how many apps based on a keyword in the table first
	cout<< "There are " << count_key << " apps with the keyword."<<endl;
	apps_list = new app_entry[count_key];	//create a dynamic array for storing app_entry class data. Size is from count_key.
	if(!haha.retrieve(keyword, apps_list, count_key))	//for finding matching apps and bringing it out
	{
		cout<<"There is no match app." << endl;	
	}
	else
	{
		if(!haha.display(apps_list,count_key))	//for display the content of the apps list.
		{
			cout<<"display error. " <<endl;
		}
	}
	if(keyword)	//deallocate the all dynamic array
	{
		delete [] keyword;
	}
	if(apps_list)
	{
		delete [] apps_list;
	}
}
*/
