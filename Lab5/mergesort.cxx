#include <iostream>

using namespace std;

void input_array(int arr[], int size);
void display(int arr[], int size);
void merge(int arr[], int first, int last, int mid);
void mergesort(int arr[], int first, int last);

int main()
{
	int input[10];
	input_array(input,10);
	display(input,10);
	mergesort(input,0,9);
	display(input,10);
	return 0;
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

void merge(int arr[], int first, int last, int mid)
{
	int t_arr[last - first + 1];
	int t_left = 0, t_right = mid+1, temp = 0;
	while(t_left < mid && t_right < last)
	{
		if(arr[t_left] <= arr[t_right])
		{
			t_arr[temp] = arr[t_left];
			t_left++;
		}
		else
		{
			t_arr[temp] = arr[t_right];
			t_right++;
		}
		temp++;
	}
	while(t_left < mid)
	{
		t_arr[temp] = arr[t_left];
		temp++;
		t_left++;
	}
	while(t_right < last)
	{
		t_arr[temp] = arr[t_right];
		temp++;
		t_right++;
	}
	for(int i = 0 ;i < last; i++)
	{
		arr[i] = t_arr[i];
	}
}

void mergesort(int arr[], int first, int last)
{
	if(first >= last -1)
	  ;
	else
	{
		int mid = (first + last) /2;
		mergesort(arr, first, mid);
		mergesort(arr, mid+1, last);
		merge(arr, first, last, mid);
	}
}
