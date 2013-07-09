class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 0;
        char pre = ' ';

        while (*s != '\0') {
            if (*s != ' ') {
                length = pre == ' '? 1: length+1;
            }

            pre = *s;
            s++;
        }

        return length;
    }
};
