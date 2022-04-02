/*
 * This program creates a heap that contains numbers.
 * By: Max Shi
 * 4/2/2022
 */

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace ::std;

struct heap {
	int arr[100];
};

bool isNum(char input[]);
int charToInt(char input[]);
void add(int heap[], int count, int toAdd);
void print(int heap[], int count, int total);
int depthOf(int index);
int removeMax(int heap[], int last);
void swap(int heap[], int index);


int main() {
	int heap[101] = {0};

  //loop that allows user to enter values for heap
	int count = 1;
	while (count <= 100) {
		char input[80];
		cin.getline(input, 80, '\n');

		if (isNum(input) == true) { //if input is a number
			add(heap, count, charToInt(input));
			count++;
		} else { //try to find file name
			fstream file;
			file.open(input);
			if (file.is_open()) {
				int num;
				while (file >> num) { //read in numbers from file
					add(heap, count, num);
					count++;
				}
			} else {
				cout << "Error opening file.\n";
			}
		}
	}
  cout<<endl;
  print(heap, 1, count-1); //print heap
  
  for(int i = 0; i < count-1; i++) //remove from largest to smallest and print
  {
    cout << removeMax(heap, count-1);
  }

}

//checks if a char array contains only numbers
bool isNum(char input[]) {
	int index = 0;
	int nonDigitCount = 0;
	while (true) {
		if (input[index] == '\0') { //break at end of cstring
			break;
		} else if (isdigit(input[index]) == 0) { //count number of non digits
			nonDigitCount++;
		}
		index++;
	}

	if (nonDigitCount > 0) { //not a number if there are any non digits
		return false;
	} else {
		return true;
	}
}

//converts char array to int
int charToInt(char input[]) {
	int index = 0;
	int intArr[80];
	while (true) { //finds length of input and converts each char to int
		if (input[index] == '\0') {
			break;
		} else {
			intArr[index] = input[index] - '0';
		}
		index++;
	}

	int num = 0;
	for (int i = 0; i < index; i++) { //multiplies each int in array by the appropriate power of 10 and sums
		num = num + intArr[i] * pow(10, (index - 1 - i));
	}
	return num;
}

//adds a value to heap
void add(int heap[], int count, int toAdd) {
	heap[count] = toAdd;

  int numOfParents = depthOf(count);
	// compares the added child to its parent
	for (int j = 0; j < numOfParents; j++) {
		if (count % 2 == 0) // even
		{
			if (toAdd > heap[count / 2]) { //if value greater than parent
				
        int temp = heap[count / 2]; //value of parent
				heap[count / 2] = toAdd; //parent = child
				heap[count] = temp; //child = parent value
				count = count / 2;
			} else {
				break;
			}
		} else if (count % 2 == 1) //odd
    {
			int tempCount = (count - 1) / 2;
			if (toAdd > heap[tempCount]) {
				int temp = heap[tempCount];
				heap[tempCount] = toAdd;
				heap[count] = temp;
				count = tempCount;
			} else {
				break;
			}
		}
	}
}

//recursively prints heap as a tree
void print(int heap[], int count, int total) {
	if (count <= total) {
		print(heap, count * 2 + 1, total); //print child 2

    //print current
    if(heap[count] != 0)
    {

      //print blank spaces based on depth of value
    int numOfParents = depthOf(count);
    for(int j = 0; j < numOfParents; j++)
      {
        cout << "   ";
      }
		cout << heap[count];
    }
    cout << endl;
    
		print(heap, count * 2, total); //print child 1
	}
}

//finds depth of an index of a heap represented as binary tree
int depthOf(int index)
{
  //keeps increasing i until the index is less than 2^i
  int i = 1;
	while (true) {
		if (index < pow(2, i)) {
			return i - 1; //0 is highest level
		} else {
			i++;
		}
	}
}

//removes the top of max heap
int removeMax(int heap[], int last)
{
  int max = heap[1];

  heap[1] = heap[last];
  heap[last] = 0;

  int depth = depthOf(last);
  int index = 1;
  for(int i = 0; i < depth; i++)
    {
      if(heap[index] < heap[index*2] && heap[index] < heap[index*2+1]) //if parent is less than both children
      {
        if(heap[index*2] < heap[index*2+1]) //swaps with the larger child
        {
          //swaps parent and child
          int childIndex = index*2+1;
          int temp = heap[index]; //store parent value
  				heap[index] = heap[childIndex]; //parent = child value
  				heap[childIndex] = temp; //child = temp
  				index = childIndex;
        }
        else
        {
          //swaps parent and child
          int childIndex = index*2;
          int temp = heap[index]; //store parent value
  				heap[index] = heap[childIndex]; //parent = child value
  				heap[childIndex] = temp; //child = temp
  				index = childIndex;
        }
      }
      else if(heap[index] < heap[index*2]) //parent is less than child 1
      {
        //swaps parent and child
        int childIndex = index*2;
        int temp = heap[index]; //store parent value
				heap[index] = heap[childIndex]; //parent = child value
				heap[childIndex] = temp; //child = temp
				index = childIndex;
      }
      else if(heap[index] < heap[index*2+1]) //parent is less than child 2
      {
        //swaps parent and child
        int childIndex = index*2+1;
        int temp = heap[index]; //store parent value
				heap[index] = heap[childIndex]; //parent = child value
				heap[childIndex] = temp; //child = temp
				index = childIndex;
      }
      
    }
  
  return max;
}

