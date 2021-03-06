/*
Find The Next Palindromic Number



Problem Statement:



Given a number n, you have to find next palindromic number pal. To be precise, you have to find an integer pal, which is smallest palindromic number, greater than n.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting integer n.



Output Format:



Return the required number pal.



Input/Output Format For The Custom Input:



Input Format:



There should be only one line, containing an integer n.



If n = 5, then input should be:



5



Output Format:



There will be one line, containing resultant integer pal.



For input n = 5, output will be:



6



Constraints:

0 <= n <= 2147483647


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



5



Sample Output 1:



6



Explanation 1:



6 is a palindromic number, and bigger than 5. There is no palindromic number less than 6 and bigger than 5.



Sample Test Case 2:



Sample Input 2:



10



Sample Output 2:



11



Notes:

Suggested time in interview: 30 minutes.

The �Suggested Time� is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TA session. Take your time, but limit yourself to 2 one hour sessions for most problems.

bool allNines( const string& str ) {
	for( int i=0; i<str.size(); ++i ) {
		if( str[i] != '9' ) return false;
	}
	return true;
}

long long int next_palindrome( int num ) {
	if( num>=0 && num<=8 ) return num+1;
	string str = to_string( num );
	if( allNines( str ) ) return num+2;

	int N = str.length();

	string leftHalf = str.substr( 0, N/2 + N%2 );
	long long int leftHalfNum = stoll( leftHalf );

	string leftHalfMirror = leftHalf;
	reverse( leftHalfMirror.begin(), leftHalfMirror.end() );
	string mirror = leftHalf + leftHalfMirror.substr( N%2 );

	long long int mirrorNum = stoll( mirror );
	if( mirrorNum > num ) return mirrorNum;

	long long int leftHalfIncNum = leftHalfNum + 1;
	string leftHalfInc = to_string( leftHalfIncNum );

	string leftHalfIncMirror = leftHalfInc;
	reverse( leftHalfIncMirror.begin(), leftHalfIncMirror.end() );
	string mirrorInc = leftHalfInc + leftHalfIncMirror.substr( N%2 );

	long long int mirrorIncNum = stoll( mirrorInc );
	return mirrorIncNum;
}

*/

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
long long int next_palindrome(int n) {

}


int main()
{
	ostream &fout = cout;

	long long int res;
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = next_palindrome(n);
	fout << res;


	return 0;
}
