class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        map<char, int> m;
        int max_length = 0;
        int tmp = 0;
        int h = 0;
        for (int i=0; i<s.size(); i++) {
            if (m.find(s[i]) != m.end() &&  m[s[i]] >= h) {
                tmp = i - m[s[i]];
                h = m[s[i]];
            } else {
                tmp++;
            }

            m[s[i]] = i;
            if (tmp > max_length) {
                max_length = tmp;
            }
        }

        return max_length;
    }
};
