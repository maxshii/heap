/*
 * This program creates a heap that contains numbers. 
 * By: Max Shi
 * 3/16/2022
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include <cmath>
using namespace::std;

struct heap
{
  int arr[100];
};

bool isNum(char input[]);
int charToInt(char input[]);

int main()
{
  while(true)
    {
      char input[80];
      cin.getline(input, 80, '\n');

      
      if(isNum(input) == true)
	{
	  cout << charToInt(input) << endl;
	}
      else
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

bool isNum(char input[])
{
  int index = 0;
  int nonDigitCount = 0;
  while(true)
    {
      if(input[index] == '\0')
	{
	  break;
	}
      else if(isdigit(input[index]) == 0)
	{
	  nonDigitCount++;
	}
      index++;	
    }

  if(nonDigitCount > 0)
    {
      return false;
    }
  else
    {
      return true;
    }
}

int charToInt(char input[])
{
  int index = 0;
  int intArr[80];
  while(true)
    {
      if(input[index] == '\0')
	{
	  break;
	}
      else
	{
	  intArr[index] = input[index] - '0';
	}
      index++;
    }

  int num = 0;
  for(int i = 0; i < index; i++)
    {
      num = num + intArr[i]*pow(10, (index-1-i));
    }
  return num;
}
