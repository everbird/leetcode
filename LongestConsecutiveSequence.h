/*
 *   http://leetcode.com/onlinejudge#question_128
 *
 * */
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_length = 1;
        map<int, int> m;
        for (int i=0; i<num.size(); i++) {
            m[num[i]] = 1;
        }

        for (int j=0; j<num.size(); j++) {
            if (m.find(num[j]) == m.end()) {
                continue;
            }

            int ltmp = num[j] - 1;
            int rtmp = num[j] + 1;
            int left = 0;
            int right = 0;
            m.erase(num[j]);

            while (m.find(ltmp) != m.end()) {
                m.erase(ltmp);
                ltmp--;
                left++;
            }

            while (m.find(rtmp) != m.end()) {
                m.erase(rtmp);
                rtmp++;
                right++;
            }

            if (left + right + 1 > max_length) {
                max_length = right + left + 1;
            }

        }

        return max_length;
    }
};
