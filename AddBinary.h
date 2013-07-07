class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int extra = 0;
        int a_length = a.size();
        int b_length = b.size();
        int max_length = a_length;
        if (b_length > a_length) {
            max_length = b_length;
        }

        string result = "";
        int ai = 0;
        int bi = 0;
        int sum = 0;
        for (int i=0; i<max_length; i++) {
            ai = a_length >= i+1? a[a_length - i - 1] - '0': 0;
            bi = b_length >= i+1? b[b_length - i - 1] - '0': 0;
            sum = ai + bi + extra;
            extra = sum >= 2? 1: 0;
            result.append(1, (sum % 2) + '0');
        }

        if (extra == 1) {
            result.append(1, '1');
        }

        string r = "";
        for (int i=result.size() - 1; i>=0; i--) {
            r.append(1, result[i]);
        }

        return r;
    }
};
