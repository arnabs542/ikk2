/*
Palindromic Decomposition Of A String



Problem Statement:



A palindromic decomposition of string is a decomposition of the string into substrings, such that all those substrings are valid palindromes.



Given a string s, you have to find ALL possible palindromic decompositions of it.



Note that string s itself is also a substring of s.



Input/Output Format For The Function:



Input Format:



There is only one argument: string s.



Output Format:



Return array of string res, containing ALL possible palindromic decompositions of given string.



To separate substrings in the decomposed string, use '|' as a separator between them. (Look at the sample test cases for more clarity.)



Note that:

You need not to worry about the order of strings in your output array. Like for s = "aa", arrays ["a|a", "aa"] and ["aa", "a|a"] both will be accepted.
In any string in your returned array res, order of characters should remain same as in given string. (i.e. for s = "ab" you should return ["a|b"] and not ["b|a"].)
Any string in the returned array should not contain any spaces. e.g. s = "ab" then ["a|b"] is expected, ["a |b"] or ["a| b"] or ["a | b"] will give wrong answer.


Input/Output Format For The Custom Input:



Input Format:



The first and only line of input should contain a string s, denoting the input string.



If s = �abracadabra�, then input should be:



abracadabra



Output Format:



Let�s denote size of res array as m, where res is the resultant array of string returned by solution function.

Then, there will be m lines of output, where ith line contains a string res[i], denoting string at index i of res.



For input s = � �, output will be:



a|b|r|a|c|ada|b|r|a

a|b|r|aca|d|a|b|r|a

a|b|r|a|c|a|d|a|b|r|a



Constraints:

1 <= |s| <= 20
s only contains lowercase letters ('a' - 'z').


Sample Test Cases:



Sample Input:



"abracadabra"



Sample Output:



[

   "a|b|r|a|c|a|d|a|b|r|a",

   "a|b|r|a|c|ada|b|r|a",

   "a|b|r|aca|d|a|b|r|a"

]



Notes:

Suggested time in interview: 40 minutes

The �Suggested Time� is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TC session. Take your time, but limit yourself to 2 one hour sessions for most problems.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Function to check if string is a palindrome or not
bool isPalindrome(string str)
{
	int start = 0, end = str.length() - 1;
	while (start < end) 
	{
		if (str[start++] != str[end--])
			return false;
	}
	return true;
}

void find_all_palindromic_decompositions(int start, string& str, string& currStr, vector<string>& res)
{
	string tempStr;

	cout << "ENTRY start = " << start << ", len = " << str.length() << ", str = " << str << 
			", currStr = " << currStr << endl;
	
	int len = str.length();

	if (start >= len)
	{
		res.push_back(currStr);
		cout << "FINISH RECURSION" << endl;
		return;
	}
	
	//loop over the string character by character
	for (int i = start; i < len; i++)
	{
		tempStr = tempStr + str[i];
		if (isPalindrome(tempStr))
		{
			cout << tempStr << "| is a palindrome" << endl;
			currStr = currStr + tempStr;

			int currLen = currStr.length();
			if (i + 1 < len)
			{
				currStr += "|";
				currLen++;
			}

			//Recurse over by advancing the start position
			find_all_palindromic_decompositions(i+1, str, currStr, res);

			if (i + 1 < len)
				currStr = currStr.substr(0, currStr.length() - (tempStr.length()+1));
			else
				currStr = currStr.substr(0, currStr.length() - tempStr.length());
			cout << "RECURSE start = " << start << ", len = " << str.length() << ", str = " << str <<
				", currStr = " << currStr << ", currLen = " << currLen << endl;
		}
	}
}

/*
 * Complete the function below.
 */
vector <string> generate_palindromic_decompositions(string s) {

	vector<string> res;
	string currStr;
	find_all_palindromic_decompositions(0, s, currStr, res);
	return res;
}

int main()
{
	ostream &fout = cout;

	vector <string> res;
	string s;
	getline(cin, s);

	res = generate_palindromic_decompositions(s);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}

	system("pause");
	return 0;
}

