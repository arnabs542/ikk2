/*
Hamming Weight



Problem Statement:



Hamming Weight of an integer x is defined as the total number of set bits in the binary representation of the integer x. Now, given an array s of n integers. We need to calculate the total hamming weight of the array s i.e. to sum-up the individual hamming weight of each integer in the array S.



Input/Output Format For The Function:



Input Format:



First and only parameter of the function that is to be implemented the array of 64-bit integers s.



Output Format:



The function returns an integer variable storing the value of the total hamming weight of the given input array s.



Input/Output Format For The Custom Input:



Input Format:



First line of the input contains one single integer n, denoting number of elements in array s.

Next n lines of the input, each line contains single integer denoting the ith element in the array s.



If n = 3 and s = [ 1, 2, 3 ], then custom input format will be:



3

1

2

3



Output Format:



Print one single line containing one integer denoting the total hamming weight of the input array s.

For the above provided custom input, output would be:



4



Constraints:

1 <= n <= 10^5
0 <= s[i] < 2^32 where 0 <= i < n.


Sample Test Case:



n = 3

s = [ 1, 2, 3 ]



Sample Output:



4



Explanation:



For the array s = [1, 2, 3], number of set bits for each element of the array is mentioned below:

Binary representation of 1 is �1� so set bits in 1 is 1.

Binary representation of 2 is �10� so set bits in 2 is 1.

Binary representation of 3 is �11� so set bits in 3 are 2.

So, total set bits in 1 + set bits in 2 + set bits in 3 are 1 + 1 + 2 = 4. Hence Summing hamming weight of given array [1, 2, 3] is 4.


int calculateHammingWeight(vector<long long> &s)
{
	int sum = 0, cursum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		cursum = 0;
		long long x = s[i];
		while (x)
		{
			cursum++;
			x = x & (x-1);
		}
		sum += cursum;
	}
	return sum;
}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the calculateHammingWeight function below.
 *
 * Complete the calculateHammingWeight function below.
 * @param s : input array as parameter.
 */

int calculateHammingWeight(vector<long long> &s)
{
}

int main()
{
	int n;
	cin >> n;

	vector<long long> s(n);

	for (int i = 0; i < n; i++)
	{
		long long int s_item;
		cin >> s_item;
		s[i] = s_item;
	}

	ostream &fout = cout;

	int result = calculateHammingWeight(s);

	fout << result << endl;

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}