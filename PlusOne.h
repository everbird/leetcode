class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<int> q;
        vector<int> r;
        int extra = 0;
        int sum = 0;

        for (int i=digits.size() - 1; i>=0; i--) {
            sum = digits[i] + extra;
            if (i==digits.size() - 1) {
                sum++;
            }
            extra = sum / 10;
            q.push_front(sum % 10);
        }
        if (extra > 0) {
            q.push_front(extra);
        }

        for (int i=0; i<q.size(); i++) {
            r.push_back(q[i]);
        }

        return r;
    }
};
