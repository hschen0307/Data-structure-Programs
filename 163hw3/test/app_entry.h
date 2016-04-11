#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
//int const key_size = 5;
class app_entry
{
      public:
             app_entry(void);
             ~app_entry(void);
             //int create_entry(char * app_name, char * notes);
	     int creat_entry(char name[], char key[], char des[], int rate);
             int copy_entry(const app_entry & a_new_entry);
             int retrieve(char * matching_keyword, app_entry & found) const;   
             //int retrieve(app_entry & found) const;   
             int display(void) const;
      private:
              char * app_name;
              char * keywords;
	      char * description;
	      int rating;				
	      				  	
};
