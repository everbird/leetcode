class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0;
        while (x != 0) {
            r = r*10 + x % 10;
            x /= 10;
        }
        return r;
    }
};
