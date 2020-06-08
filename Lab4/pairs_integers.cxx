#include <iostream>
#include <fstream>

using namespace std;

void create_input(int arr[], int size);
void insertionsort(int arr[], int size);
void find_pairs(int arr[], int size);
int binarysearch(int arr[], int size, int val);

const int MAX_SIZE = 10;

int main()
{
	//Create an input array containing 10 input values and a new file 
	//named "create_number.txt".
	//Copy the values to the new txt file 
	int input[MAX_SIZE];
	create_input(input,MAX_SIZE);
	
	//Check the array
	cout <<"input array = ";
	for(int i = 0; i <MAX_SIZE ;i++)
	  cout << input[i]<<' ';
	cout << endl;
	
	//Sort the values by insertion sort
	insertionsort(input,MAX_SIZE);
	
	//Check the sorted result
	for(int i = 0; i <MAX_SIZE ;i++)
	  cout << input[i]<<' ';
	  
	// Find pairs  
	find_pairs(input,MAX_SIZE);
}

void create_input(int arr[], int size)
{
	ofstream create_number("create_number.txt");
	int i = 0, input_num;
	while(i < size)
	{
		cin >> input_num;
		arr[i] = input_num;
		create_number << input_num << endl;
		i++;
	}	
}


void insertionsort(int arr[], int size)
{
	int i, j, temp;
	for(i = 1; i < size; i++)
	{
		j = i; 
		while(arr[j] < arr[j-1] && j > 0)
		{
			temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}

void find_pairs(int arr[], int size)
{
	int sum, pair, result;
	cout << "All pairs in an array of integers whose sum is equal to a given value: ";
	cin >> sum;
	cout << endl;
	for(int i=0; i < size; i++)
	{
		//If 2 numbers are in pair, given number1, number2 should be found in array.
		//Use binary search to find number2. 
		pair = sum - arr[i];
		result = binarysearch(arr,size,pair);
		if(result >= 0 && result < size)
		{
			if(result != i)
			{
				cout << "(" << arr[i] << "," << pair << ")";
			}
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
	//If there's no number2, return -1 
	return -1;
}


/*Sample:
2
4
7
5
9
10
1
13
12
8
input array = 2 4 7 5 9 10 1 13 12 8
1 2 4 5 7 8 9 10 12 13 All pairs in an array of integers whose sum is 
equal to a given value: 10

(1,9)(2,8)(8,2)(9,1)

----------------------------
2
4
7
5
9
10
-1
8
11
13
input array = 2 4 7 5 9 10 -1 8 11 13
-1 2 4 5 7 8 9 10 11 13 All pairs in an array of integers whose sum is 
equal to a given value: 9

(-1,10)(2,7)(4,5)(5,4)(7,2)(10,-1)
 */
