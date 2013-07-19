class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int>::iterator it = num.end() - 1;
        while (it != num.begin() && *(it-1) >= *it) {
            it--;
        }

        if (it == num.begin()) {
            reverse(num.begin(), num.end());
            return;
        }

        it--;

        vector<int>::iterator rit = it+1;
        while (rit != num.end() && *rit > *it) {
            rit++;
        }
        rit--;

        iter_swap(it, rit);
        reverse(it+1, num.end());
    }
};
