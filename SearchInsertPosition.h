class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (target <= A[0]) {
            return 0;
        }

        for (int i=0; i<n; i++) {
            int next = i+1;
            if (next >= n) {
                return A[i] >= target? i: next;
            } else if (A[next] > target && A[i] <= target) {
                return A[i] == target? i: next;
            }
        }
        return n;
    }
};
