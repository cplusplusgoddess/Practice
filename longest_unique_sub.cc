#include <algorithm>
#include <iostream>
#include <vector>
#include "print.hh"

using namespace std;

bool checkRepetition(string& s, int start, int end) {
    vector<int> chars(128);

    for (int i = start; i <= end; i++) {
        char c = s[i];
        chars[c]++;
        if (chars[c] > 1) {
            return false;
        }
    }

    return true;
}

int brute_lengthOfLongestSubstring(string s) {
    int n = s.length();

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}
/* Time Complexity: O(N^2), where N is the length of the string.
Space Complexity: O(min(N,M)), as a visiting array is used. 
N is the length of the string and M is the size of the substrings.
*/
int slideview_lengthOfLongestSubstring(string str)
{
    int n = str.size();
    int res = 0;  
    for (int i = 0; i < n; i++) {
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == true)
                break;
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
         visited[str[i]] = false;
    }
    return res;
}
/*
  Time Complexity: O(N), where N is the length of the string.
  Space Complexity: O(min(N,M)), as HashSet is used. 
  N is the length of the string and M is the size of the substrings.
*/
int optimal_lengthOfLongestSubstring(string s) {
        vector<int> chars(128);
 
        int left = 0;
        int right = 0;
 
        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;
 
            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }
 
            res = max(res, right - left + 1);
 
            right++;
        }
 
        return res;
}


int main() {
    // Your code goes here;
    string s = "abcabcbca";
	printer<string> p;
	p.print("Input string: ", s);
    cout << optimal_lengthOfLongestSubstring(s) << endl;
    return 0;
}
