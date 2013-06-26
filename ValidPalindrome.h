class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string t;
        for (int i=0; i<s.size(); i++) {
            char x = s.at(i);
            if (x >= int('0') && x <= int('9') || x >=int('a') && x <=int('z') || x >=int('A') && x<=int('Z')) {
                t.push_back(tolower(x));
            }
        }

        int b = 0;
        int e = t.size() - 1;
        while (b < e) {
            if (t.at(b) != t.at(e)) {
                return false;
            }
            b++;
            e--;
        }

        return true;
    }
};
