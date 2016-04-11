#include "app_entry.h"
//This file define all public functions of class app_entry.
//construtor
//initialize all private members in this class.
app_entry::app_entry(void)
{
	app_name = NULL;	//let all pointers point to NULL
	keywords = NULL;	//let all int variables equals to zero.
	total_key = 0;
	description = NULL;
	rating = 0;
}
//destructor
//deallocate all dynamic memory.
app_entry::~app_entry(void)
{
	if(app_name)	//check the memoy first before delete it
		delete [] app_name;	//delete the dynamic memory
	if(keywords)	
	{
		for(int i=0;i<total_key;++i) //'keywords' is a dynamic array of dynamic arrays, so we need a for loop to delete the arrays in it first.
		{
			if(keywords[i])
				delete [] keywords[i];
		}
		delete [] keywords; //delete 'keywords' itself.
	}
	if(description)
	{
		delete [] description;	//delete description
	}
	
}
//This function is for creating a new entry object which stores information from a user types in. 
//intput:: a app's name, a app's key word list, a total number of keywords of a app, a description,and a rating.
//output:: 1, when creating a object successfully. 0, unsuccessully.
int app_entry::creat_entry(char* name, char* key[],int all_key, char* des, int rate)
{
	if(!name || !key || !des)	//check whether arrays are empty. if one of them is empty, it will directly return 0. 
	{
		return 0;
	} 
	app_name = new char[strlen(name)];	//create a new dynamic array. The size is up to the name just passed in. 
	keywords = new char*[all_key]; 		//same as app_name
	description = new char[strlen(des)];	
	strcpy(app_name,name);			//copy the name to the object's app_name.
	for(int i=0; i<all_key; ++i)		//copy all keywords to the object's keywords list.
	{
		keywords[i]=new char[strlen(key[i])];
		strcpy(keywords[i],key[i]);
	}
	total_key = all_key;		//copy the total number of keywords
	strcpy(description, des);	//copy the description
	rating = rate;			//copy the rating
	return 1;			//success 
}
//This function is for copying all information from a entry object
//input::app_entry type of a object
//output:: 1,success. 0, unsuccess.
int app_entry::copy_entry(const app_entry & copy_from)
{    
		
       if(app_name) 			//check whether private members are empty. If they are not empty, delete all the content first.
       	  delete [] app_name;		
       if(keywords)
	  delete [] keywords;
       if(description)
	  delete [] description;	
      					
       if(copy_from.app_name==NULL || copy_from.description ==NULL || copy_from.keywords == NULL)//if the data of copy soruce is empty, return 0. 
       {
           return 0;
       } 

       app_name = new char[strlen(copy_from.app_name)];		//copy all the information from copy_from to the private memebers in this object.
       keywords = new char*[copy_from.total_key];		
       description = new char[strlen(copy_from.description)];
       strcpy(app_name, copy_from.app_name); 
       for(int i=0; i<copy_from.total_key;++i)			//copy whole keywords list by using a for loop.	
       {	
		keywords[i]= new char[strlen(copy_from.keywords[i])];	
        	strcpy(keywords[i], copy_from.keywords[i]); 
       }
       total_key = copy_from.total_key;
       strcpy(description, copy_from.description); 
       rating = copy_from.rating;
       return 1; 						//success
}
//This function is for finding matching apps based on a keyword.
//input:: a keyword, and a object for copying the information when getting match. 
//output:: 1, when getting matching and complete copying. 0, when it there is no match.
int app_entry::retrieve(char * matching_keyword, app_entry & found)const
{
      for(int i=0; i<total_key; ++i)  		//access evey keyword in a node.
      {		
      	if(strcmp(matching_keyword,keywords[i])== 0)  //compare a keyword of a node with a matching keyword
      	{
            found.app_name = new char[strlen(app_name)];	//if there is a match, copy all the information of this node to the 'found' object.
            strcpy(found.app_name,app_name);
	    found.keywords = new char*[total_key];
	    for(int i=0; i<total_key;++i)		//use a for loop to copy the all keywords in the node.
	    {	
		found.keywords[i]= new char[strlen(keywords[i])];
            	strcpy(found.keywords[i],keywords[i]);
	    }	
	    found.total_key = total_key;		
	    found.description = new char[strlen(description)];		
            strcpy(found.description,description);		
	    found.rating = rating;	
            return 1;				//success	
      	}
      }	  
      return 0;					//fail
}
//this fuction is for finding matching keyword of a node and return number of a match for counting. 
//input:: a  keyword 
//output:: 1,if there is a match. 0,if there is no match.
int app_entry::count_key(char * matching_keyword)const
{
      for(int i=0; i<total_key; ++i)	//for accessing every keyword.
      {		
      	if(strcmp(matching_keyword,keywords[i])== 0)  //compare a key word and the matching key word,get match, return 1.
      	{
            return 1;
      	}
      }	  
      return 0;		//no matchm return 0

}
//this function is for display all information of a node.
//input::no
//output::1,when display successfully.
int app_entry::display(void) const		
{	
	cout<<"app_name : " << app_name << endl;
	cout<<"keywords : " ;
	for(int i=0;i<total_key;++i)
	{
		cout<< keywords[i]<<" ,";
	}
	cout<<endl;
	cout<<"description : " << description << endl;
	cout<<"rating : " << rating<<endl;
	return 1;
}





















