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
int add(int heap[], int count);

int main()
{
  int heap[101] = {0};
  int count = 1;
  while(count <= 101)
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

int add(int heap[], int count, int toAdd)
{
  heap[count] = toAdd;

  int i = 1;
  int numOfParents = 0;
  while(true)
    {
      if(count < pow(2, i))
	{
	  numOfParents = i-1;
	  break;
	}
      else
	{
	  i++;
	}
	    
    }

  //compares the added child to its parent
  for(int j = 0; j<numOfParents; j++)
    {
      if(count%2 == 0) //even
	{
	  if(toAdd > heap[count/2])
	    {
	      int temp = heap[count/2];
	      heap[count/2] = toAdd;
	      heap[count] = temp;
	      count = count/2;
	    }
	  else
	    {
	      break;
	    }
	}
      else if(count%2 == 1)
	{
	  int tempCount = (count - 1) / 2;
	  if(toAdd > heap[tempCount))
	  {
	    int temp = heap[tempCount];
	    heap[tempCount] = toAdd;
	    heap[count] = toAdd;
	    count = tempCount;
	  }
	  else
	    {
	      break;
	    }
	}	    
      
    }
	

}
