#include <iostream>

using namespace std;

void input_array(int arr[], int size);
void display(int arr[], int size);
int binarysearch(int arr[], int left, int right, int val);

int main()
{	
	int array[10];
	int value,index;
	input_array(array,10);
	display(array,10);
	cout << "Search Value: ";
	cin >> value;
	index = binarysearch(array,0,9,value);
	cout << "Index of value: " << index << endl;
}

void input_array(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}	
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	   cout << arr[i] << " ";
	cout << endl;
}

int binarysearch(int arr[], int left, int right, int val)
{
	int mid = (left + right) /2;
	if(left > right)
	  return -1;
	if(arr[mid] == val)
	  return mid;
	else if(arr[mid] < val)
	{
		left = mid +1;
		binarysearch(arr,left,right,val);
	}
	else if(arr[mid] > val)
	{
		right = mid -1;
		binarysearch(arr,left,right,val);
	}
}

/*Sample:
1 2 3 4 5 6 7 8 9 10
Search Value: 3
Index of value: 2

1 2 3 4 5 6 7 8 9 10
Search Value: 11
Index of value: -1
*/
