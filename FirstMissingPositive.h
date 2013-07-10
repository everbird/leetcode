class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool s[1024] = {false};

        for (int i=0; i<n; i++) {
            if (A[i] >= 0) {
                s[A[i]] = true;
            }
        }

        for (int j=1; j<1024; j++) {
            if (!s[j]) {
                return j;
            }
        }

        return -1;
    }
};
