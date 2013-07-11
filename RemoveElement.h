class Solution {
public:
    int remove_count;
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->remove_count = 0;
        for (int i=0; i<n; i++) {
            int new_index = i - this->remove_count;
            if (A[new_index] == elem) {
                this->remove(A, n - this->remove_count, new_index);
                this->remove_count++;
            }
        }
        return n - this->remove_count;
    }

    void remove(int A[], int n, int pos) {
        for (int i=pos; i<n-1; i++) {
            this->swap(A, i, i+1);
        }
        return;
    }

    void swap(int A[], int a, int b) {
        A[a] ^= A[b];
        A[b] = A[a] ^ A[b];
        A[a] ^= A[b];
    }
};
