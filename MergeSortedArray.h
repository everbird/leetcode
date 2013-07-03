class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 0) {
            return;
        }

        if (m == 0) {
            for (int i=0; i<n; i++) {
                A[i] = B[i];
            }
            return;
        }

        int T[m];
        for (int i=0; i<m; i++) {
            T[i] = A[i];
        }

        int indexa = 0;
        int indexb = 0;
        int index = 0;

        while (indexa < m || indexb < n) {
            if (indexa >= m) {
                A[index] = B[indexb];
                indexb++;
            } else if (indexb >= n) {
                A[index] = T[indexa];
                indexa++;
            } else if (T[indexa] > B[indexb]) {
                A[index] = B[indexb];
                indexb++;
            } else if (T[indexa] <= B[indexb]){
                A[index] = T[indexa];
                indexa++;
            }
            index++;
        }

        return;
    }
};
