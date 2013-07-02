class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_sum = A[0];
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += A[i];
            if (sum > max_sum) {
                max_sum = sum;
            }
            if (sum < 0) {
                sum=0;
            }
        }
        return max_sum;
    }
};
