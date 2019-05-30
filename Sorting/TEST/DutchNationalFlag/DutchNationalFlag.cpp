/*
Dutch National Flag



Problem Statement:



You are given n balls. Each of these balls are of one the three colors: Red, Green and Blue. They are arranged randomly in a line. Your task is to rearrange them such that all balls of the same color are together and their collective color groups are in this order: Red balls first, Green balls next and Blue balls last.



This combination of colors is similar to the Dutch National Flag, hence the problem name.



This is a popular sorting problem.



Input/Output Format For The Function:



Input Format:



An array of characters named balls, consisting of letters from {�R�, �G�, �B�}, where each letter represents a ball with color.



'R' = Red Ball

'G' = Green Ball

'B' = Blue Ball



Balls are arranged in the line, in the same order as they appear in balls.



Output Format:



Return type is void. You have to do it in-place i.e. you need to modify the input character array balls.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting no. of balls. In next n lines, ith line should contain one letter from {'R', 'G', 'B'}, balls[i], denoting color of ith ball.



If balls = [G, B, G, G, R, B, R, G], then input should be:



8

G

B

G

G

R

B

R

G



Output Format:



There will be n lines of output, where ith line contains a character balls[i], denoting character at index i of balls.

Here, balls is the character array after the function that you are going to complete is called.



For input balls = [G, B, G, G, R, B, R, G], output will be:



R

R

G

G

G

G

B

B



Constraints:



1 <= n <= 100000
Do this in ONE pass over the array - NOT TWO passes, just one pass.
Your solution can only use O(1) extra memory i.e. you have to do this in-place. Don't use any other memory for processing.


Sample Test Case:



Sample Input:



balls = [G, B, G, G, R, B, R, G]



Sample Output:



[R, R, G, G, G, G, B, B]



Explanation:



In the input there are total 2 red balls, 4 green balls and 2 blue balls. In output red balls should come first, then green and then blue. So, [R, R, G, G, G, G, B, B] is the correct output.



Notes:



Maximum time allowed in interview: 20 Minutes.



A naive solution to this problem, is to simply count how many balls of each color, and then overwrite the array with that many balls in the expected order of colors. However, realize that that is not how it's ""practically"" feasible to do ""with actual balls"". i.e. you can overwrite variables in a program, but there is no way to "overwrite" a ball of a certain color with another color. i.e. that is an invalid solution.

#include <algorithm>
using namespace std;

void dutch_flag_sort(vector<char>& balls) {

	int i = 0;
	int j = balls.size();
	int c = 0;
	while (c < j) {
		if (balls[c] == 'R') {
			swap(balls[i++], balls[c++]);
		} else if (balls[c] == 'B') {
			swap(balls[--j], balls[c]);
		} else {
			c++;
		}
	}

}

*/

#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

void dutch_flag_sort(vector<char>& balls) {

}


int main()
{
	ostream &fout = cout;

	string balls_count_temp;
	getline(cin, balls_count_temp);

	int balls_count = stoi(ltrim(rtrim(balls_count_temp)));

	vector<char> balls(balls_count);

	for (int i = 0; i < balls_count; i++) {
		string balls_item_temp;
		getline(cin, balls_item_temp);

		char balls_item = balls_item_temp[0];

		balls[i] = balls_item;
	}

	dutch_flag_sort(balls);

	for (int i = 0; i < balls.size(); i++) {
		fout << balls[i];

		if (i != balls.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	return 0;
}


string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

