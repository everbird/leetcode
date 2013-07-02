class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int indexa = 0;
        int indexb = 0;
        int index = 0;
        int target = (m+n) / 2;

        if ((m + n) % 2 == 1) {

            if (m == 0) {
                return B[target];
            } else if (n == 0) {
                return A[target];
            }
            int t = 0;

            while (index <= target) {
                if (indexb >= n) {
                    t = A[indexa++];
                    index++;
                    continue;
                } else if (indexa >= m) {
                    t = B[indexb++];
                    index++;
                    continue;
                }

                if (A[indexa] <= B[indexb]) {
                    t = A[indexa++];
                } else {
                    t = B[indexb++];
                }
                index++;
            }

            return t;
        } else {
            if (m == 0) {
                return (double)(B[target] + B[target-1]) / 2;
            } else if (n == 0) {
                return (double)(A[target] + A[target-1]) / 2;
            }
            int t = 0;
            while (index < target) {
                if (indexb >= n) {
                    t = A[indexa++];
                    index++;
                    continue;
                } else if (indexa >= m) {
                    t = B[indexb++];
                    index++;
                    continue;
                }

                if (A[indexa] <= B[indexb]) {
                    t = A[indexa++];
                } else {
                    t = B[indexb++];
                }
                index++;
            }
            int this_one = 0;
            if (indexa >= m) {
                this_one = B[indexb];
            } else if (indexb >= n) {
                this_one = A[indexa];
            } else if (A[indexa] <= B[indexb]) {
                this_one = A[indexa];
            } else {
                this_one = B[indexb];
            }

            int pre_one = t;
            return (double)(this_one + pre_one) / 2;
        }
    }
};
