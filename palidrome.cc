
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
// A C++ program to implement Manacher’s Algorithm
 
#define ACTUAL_TEXT_R(C, radius)((C+radius+1)/2)
#define ACTUAL_TEXT_L(C, radius)((C-radius-1)/2)

string longestPalindrome(string s)
{
    int N = s.length();
    if ((N == 0) || (N == 1) )
        return(s);
 
    // Position count
    N = 2 * N + 1;
 
    // LPS Length Array
    int palindromeRadii[N];
    palindromeRadii[0] = 0;
    palindromeRadii[1] = 1;
 
    // centerPosition
    int C = 1;
 
    // centerRightPosition
    int R = 2;
 
    // currentRightPosition
    int currR = 0;
 
    // currentLeftPosition
    int iMirror;
    int expand = -1;
    int diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
 
    // Uncomment it to print LPS Length array
    printf("%d %d ", palindromeRadii[0], palindromeRadii[1]);
    for (currR = 2; currR < N; currR++) {
        // Get currentLeftPosition iMirror
        // for currentRightPosition i
        iMirror = 2 * C - currR;
 
        // Reset expand - means no
        // expansion required
        expand = 0;
        diff = R - currR;
 
        // If currentRightPosition currR is
        // within centerRightPosition R
        if (diff >= 0) {
 
            // Case 1
            if (palindromeRadii[iMirror] < diff)
                palindromeRadii[currR] = palindromeRadii[iMirror];
 
            // Case 2
            else if (palindromeRadii[iMirror] == diff && R == N - 1)
                palindromeRadii[currR] = palindromeRadii[iMirror];
 
            // Case 3
            else if (palindromeRadii[iMirror] == diff && R < N - 1) {
                palindromeRadii[currR] = palindromeRadii[iMirror];
 
                // Expansion required
                expand = 1;
            }
 
            // Case 4
            else if (palindromeRadii[iMirror] > diff) {
                palindromeRadii[currR] = diff;
 
                // Expansion required
                expand = 1;
            }
        }
        else {
            palindromeRadii[currR] = 0;
 
            // Expansion required
            expand = 1;
        }
 
        if (expand == 1) {
 
            // Attempt to expand palindrome centered
            // at currentRightPosition currR. Here for odd
            // positions, we compare characters and
            // if match then increment LPS Length by ONE
            // If even position, we just increment LPS
            // by ONE without any character comparison
  			// Note: palindromeRadii looks like s but with'|' 
            // surrounding each character, to handle where
            // the center is in the middle ie is even e.g. abcaacba
    
            while (((currR + palindromeRadii[currR]) < N && 
				   (currR - palindromeRadii[currR]) > 0) && 
				(((currR + palindromeRadii[currR] + 1) % 2 == 0) || // on a | or
                (s[ACTUAL_TEXT_R(currR, palindromeRadii[currR])] == // s[right]==
                 s[ACTUAL_TEXT_L(currR, palindromeRadii[currR])]))) // s[left]
			{
                palindromeRadii[currR]++;
            }
        }
 
        // Track maxLPSLength
        if (palindromeRadii[currR] > maxLPSLength) {
            maxLPSLength = palindromeRadii[currR];
            maxLPSCenterPosition = currR;
        }
 
        // If palindrome centered at
        // currentRightPosition currR expand
        // beyond centerRightPosition R,
        // adjust centerPosition C based
        // on expanded palindrome.
        if (currR + palindromeRadii[currR] > R) {
            C = currR;
            R = currR + palindromeRadii[currR];
        }
 
        // Uncomment it to print LPS Length array
        cout <<  palindromeRadii[currR] << " " ;
    }
 
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
 
    cout << "start: " << start << " end: " << end << endl;
    cout << "LPS of string is " << s << " : ";
 
	cout << s.substr(start, maxLPSLength) << endl;
	return(s.substr(start, maxLPSLength));
}
 
 
int main(){


    string text1 = "babcbabcbaccba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "abaaba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
    longestPalindrome(text1);
 
    text1 = "abababa";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "abcbabcbabcba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "forgeeksskeegfor";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "caba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "abacdfgdcaba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "abacdfgdcabba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "abacdedcaba";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;
 
    text1 = "a";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;

    text1 = "";
	cout << "Longest for " << text1 << " is: " << longestPalindrome(text1) << endl;

  return(0);
}
