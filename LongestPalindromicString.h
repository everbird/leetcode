/*
 *
 * Longest Palindromic Substring
 * 
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *
 * */
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.size();

        if (N == 0) {
            return "";
        }

        if (N == 1) {
            return s;
        }

        int d[N][N];
        for (int i=0; i< N; i++) {
            for (int j=0; j<N; j++) {
                if (i < j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = 1;
                }
            }
        }

        int k;
        int ri = 0;
        int li = 0;
        int max_length = 1;
        for (int k=1; k < N; k++) {
            for (int m=0; m < N - k; m++) {
                int n = m + k;
                if (s[m] != s[n]) {
                    d[m][n] = 0;
                } else {
                    d[m][n] = d[m+1][n-1];
                    if (d[m][n] == 1 && k+1 > max_length) {
                        max_length = k+1;
                        ri = n;
                        li = m;
                    }
                }
            }
        }

        return s.substr(li, ri-li+1);
    }
};
