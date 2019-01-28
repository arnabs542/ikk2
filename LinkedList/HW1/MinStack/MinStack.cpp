/*Implement A Min Stack

Problem Statement :
You have to build a min stack.Min stack should support push, pop methods(as usual stack) as well as one method that returns the minimum element in the entire stack.
You are given an integer array named operations of size n, containing values >= -1.

operations[i] = -1 means you have to perform a pop operation.
operations[i] = 0 means you need to find the minimum element in the entire stack and add it at the end of array to be returned.
operations[i] >= 1 means you you need to push operations[i] on the stack.


Input / Output Format For The Function :

Input Format :
There is only one argument in input, denoting integer array named operations.

Output Format :
Return an integer array res, containing answer for each operations[i] = 0.


Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting length of operations array.In next n lines, ith line should contain an integer operations[i], denoting value at index i of operations array. (i = 0, 1, ..., n - 1)
If n = 7 and operations = [10, 5, 0, -1, 0, -1, 0], then input should be :

7
10
5
0
- 1
0
- 1
0

Output Format :
Let�s denote the total number of min query operations(i.e.operations[j] = 0) in input array operations as x.So, length of returned array res must be x.
There will be x lines, where ith line contains an integer res[i], denoting value at index i of res.

For input n = 7 and operations = [10, 5, 0, -1, 0, -1, 0], output will be :

5
10
- 1

Constraints:

1 <= n <= 100000
- 1 <= operations[i] <= 2 * 10 ^ 9, (i = 0, 1, ..., n - 1)
If stack is empty, then do nothing for pop operation.
If stack is empty, then consider - 1 as the minimum element.

Sample Input :
[10 5 0 - 1 0 - 1 0]

Sample Output :
[5 10 - 1]

Explanation :

Initially stack = [], ans = [].
operations[0] = 10->push->stack = [10], ans = []
operations[1] = 5->push->stack = [10 5], ans = []
operations[2] = 0->get minimum element->stack = [10, 5], ans = [5]
operations[3] = -1->pop->stack = [10], ans = [5]
operations[4] = 0->get minimum element->stack = [10], ans = [5 10]
operations[5] = -1->pop->stack = [], ans = [5, 10]
operations[6] = 0->get minimum element->stack = [], ans = [5 10 - 1](as stack is empty we have to consider - 1 as the minimum element.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack
{
private:
	std::vector<int> minStack_;

public:
	
	void pop()
	{
		if (!minStack_.empty())
			minStack_.pop_back();
	}

	void push(int data)
	{
		minStack_.push_back(data);
	}

	int min()
	{
		if (minStack_.empty())
			return -1;
		else
		{
			int min = INT_MAX;
			for (auto& it : minStack_)
			{
				if (it < min)
					min = it;
			}
			return min;
		}
	}
};

/*
 * Complete the function below.
 */
vector<int> min_stack(vector<int> operations) 
{
	MinStack* st = new MinStack();
	std::vector<int> output;

	for (int i = 0; i < operations.size(); i++)
	{
		int op = operations[i];
		switch (op)
		{
			case 0:		//find minimum elements in entire stack
			{
				int min = st->min();
				output.push_back(min);
				break;
			}
			case -1:	//Pop element from the stack
			{
				st->pop();
				break;
			}
			default:	//Push element into the stack
			{
				st->push(op);
				break;
			}
		}
	}
	return output;
}

int main()
{
	ostream &fout = cout;

	int operations_size;
	cin >> operations_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> operations(operations_size);
	for (int operations_i = 0; operations_i < operations_size; operations_i++) {
		int operations_item;
		cin >> operations_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		operations[operations_i] = operations_item;
	}

	vector<int> res = min_stack(operations);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	system("pause");
	return 0;
}
