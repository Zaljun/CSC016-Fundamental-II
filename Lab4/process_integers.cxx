#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int read_input(int array[],int size);
void insertionsort(int array[], int size);
int binarysearch(int array[], int size, int val);

const int MAX_SIZE = 30;

int main()
{
	int hours[MAX_SIZE];
	int actual_size, value, result_index;
	/*for(int i = 0; i < MAX_SIZE; i++)
	{
		cout << hours[i] << " ";
	}*/
	actual_size = read_input(hours,MAX_SIZE);
	//cout << actual_size << endl;
	for(int i = 0; i < actual_size; i++)
		cout << hours[i] << " ";
	cout << endl;
	insertionsort(hours,actual_size);
	cout << "Sorted list: " << endl;
	for(int i = 0; i < actual_size; i++)
	    cout << hours[i] << " ";
	cout << endl << "What value do you want to search?" << endl;
	cin >> value;
	result_index = binarysearch(hours, actual_size, value);
	cout << result_index;
}

int read_input(int array[], int size)
{
	ifstream inFile;
	inFile.open("input.txt");
	int i = 0;
	while(inFile >> array[i] && i < MAX_SIZE)
	{
		i++;
	}
	return i;
}

void insertionsort(int array[], int size)
{
	int i, j, temp;
	for(i = 1; i < size; i++)
	{
		j = i; 
		while(array[j] < array[j-1] && j > 0)
		{
			temp = array[j-1];
			array[j-1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

int binarysearch(int arr[], int size, int val)
{
	int left = 0, right = size - 1, mid;
	while(right >= left)
	{
		mid = (left + right) / 2;
		if(arr[mid] == val)
		  return mid;
		else if(arr[mid] > val)
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}
	return -1;
}


/*Sample1:
18 12 19 35 21 20 17 5 18 42 22 40 19 39 25
Sorted list:
5 12 17 18 18 19 19 20 21 22 25 35 39 40 42
What value do you want to search?
5
0
------------------
18 12 19 35 21 20 17 5 18 42 22 40 19 39 25
Sorted list:
5 12 17 18 18 19 19 20 21 22 25 35 39 40 42
What value do you want to search?
18
3
------------------
18 12 19 35 21 20 17 5 18 42 22 40 19 39 25
Sorted list:
5 12 17 18 18 19 19 20 21 22 25 35 39 40 42
What value do you want to search?
42
14
* /
