/*
 * This program creates a heap that contains numbers. 
 * By: Max Shi
 * 3/16/2022
 */

#include <iostream>
#include <fstream>
#include <cctype>
using namespace::std;

struct heap
{
  int arr[100];
};

int main()
{
  while(true)
    {
      char input[80];
      cin.getline(input, 80, '\n');

      if(true)
	{
	  fstream file;
	  file.open(input);
	  if(file.is_open())
	    {
	      int num;
	      while(file >> num)
		{
		  cout << num << endl;
		}
	    }
	  else
	    {
	      cout << "Error opening file.\n";
	    }
	}
    }
  
}
