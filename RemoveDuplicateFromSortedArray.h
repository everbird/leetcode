class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 0;
        int pre = -pow(2,31);

        int B[1024] = {0};
        for (int i=0; i<n; i++) {
            int current = A[i];
            if (current != pre) {
                pre = current;
                B[length] = current;
                length++;
            }
        }

        //memcpy(A, B, length);

        for (int i=0; i<length; i++) {
            A[i] = B[i];
        }

        return length;
    }
};
