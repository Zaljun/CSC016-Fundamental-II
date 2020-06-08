#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

bool check_conflict(int *board, int index, int ind_check); // true if no conflicts
// different row
// board[i] = board[j]
// main diagonal
// row - col the same
// board[i] - i = board[j] - j
// other diagonal
// row + col the same
// board[i] + i = board[j] + j
bool backtracking(int *board, int index, int n);  // true if find the correct place
void find_queen(int n);
const int ind_first = 0;

int main()
{
	int n;
	cout << "Input N (N is between 4 and 100)" << endl;
	cin >> n;
	clock_t t_start, t_end, duration;
	t_start = clock();
	find_queen(n);
	t_end = clock();
	duration = (double)(t_end - t_start)*1000/CLOCKS_PER_SEC;
	cout << duration << endl;
	return 0;
}

void find_queen(int n)
{
	// initialize array
	assert(n >= 4);
	int *board = new int[n];
	for(int i = 0; i < n; i++)
	  board[i] = -1;
	// test
	/*for(int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	cout << check_conflict(board,3,ind_first);*/
    cout << backtracking(board,ind_first,n) << endl;
	//display
	for(int i = 0; i < n; i++)
	  cout << board[i] << ' ';
	cout << endl;
}

bool backtracking(int *board, int index, int n)
{
	if(index == n)
	  return true;
	else
	{
		//for(board[index] = 0; board[index] < n; board[index]++)
		board[index] = 0;
		do
		{
			if(check_conflict(board,index,ind_first))
			{
				if(backtracking(board,index+1,n) == false)
				  board[index]++;
				else
				  return true;
			}
			else
			  board[index]++;
		}while(board[index] < n);
		return false;
	}
}

bool check_conflict(int *board, int index, int ind_check)
{
	if(ind_check == index)
	  return true;
	else
	{
		if(board[index] != board[ind_check])
		{
			if(board[index] - index != board[ind_check] - ind_check)
			{
				if(board[index] + index != board[ind_check] + ind_check)
				{
					return  check_conflict(board,index,ind_check+1);
				}
				//return false;
			}
			//return false;
		}
		return false;	
	}
}
