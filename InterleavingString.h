class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
        int dp[100][100];
        int m = s1.length();
        int n = s2.length();

        if (m + n != s3.length()) {
            return false;
        }

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = false;
            }
        }

        dp[0][0] = true;

        if (s1.length())
            for (int i = 0; i < m; i++) {
                if (s1[i] == s3[i]) {
                    dp[i+1][0] = true;
                }
            }
        if (s2.length())
            for (int j = 0; j < n; j++) {
                if (s2[j] == s3[j]) {
                    dp[0][j+1] = true;
                }
            }

        if (s1.length() && s2.length()) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    } else if (s1[i-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i-1][j];
                    } else if (s2[j-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[m][n];
    }
};
