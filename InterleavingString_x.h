class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        if (s1.length() == 0) {
            return s2 == s3;
        }

        if (s2.length() == 0) {
            return s1 == s3;
        }

        char a1 = s1[0];
        char a2 = s2[0];
        char a3 = s3[0];

        return (a1==a3 && this->isInterleave(s1.substr(1), s2, s3.substr(1)))
                || (a2==a3 && this->isInterleave(s1, s2.substr(1), s3.substr(1)));
    }
};
