/*

Run Length Encoder



Problem Statement:



Compress a string (only has alphabet characters), with basic encoding, where you simply count the number of repeated characters. Then also write a routine to decompress it.



e.g.

Input: "AAAAA"

Output: "5A"



Input: "BAAAB"

Output: "B3AB"



Input: "ABAB"

Output: "ABAB" [We are not concerned about characters repeating in groups]



Assume that a given character will not repeat more than 127 times.



Input format:



There is only one argument named strInput denoting the input string.



Output format:



Return the compressed string



Constraints:

String consists of alphabetic characters only
1 <= length_of_input_string <= 6500


Sample Test Cases:



Sample Input 1:



AAAAA



Sample Output 1:



5A



Explanation 1:



Character �A� is repeated 5 times consecutively.



Sample Input 2:



ABaaaBCC



Sample Output 2:



AB3aB2C



Explanation 2:



Character �a� is repeated 3 times in consecutively, character �C� is repeated 2 times consecutively.


string RLE(string strInput) {
	int i, count, n = strInput.length();
	string ret;

	while (i < n) {
		count = 1;
		while (i < n - 1 && strInput[i] == strInput[i + 1]) {
			count++;
			i++;
		}

		if (count > 1) {
			ret += to_string(count);
		}
		ret.push_back(strInput[i]);
		i++;
	}

	return ret;
}

*/


#include <bits/stdc++.h>

using namespace std;

/*
	Complete the function below
*/
string RLE(string strInput) {

}

int main() {
	string s;
	cin >> s;
	string result = RLE(s);
	cout << result << endl;
	return 0;
}
