class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        int pos = this->binarySearch(A, 0, n-1, target);
        int pos_start = this->searchDown(A, pos);
        int pos_end = this->searchUp(A, pos, n);
        r.push_back(pos_start);
        r.push_back(pos_end);
        return r;
    }

    int binarySearch(int A[], int start, int end, int target) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (A[mid] > target) {
            end = mid - 1;
        } else if (A[mid] < target) {
            start = mid + 1;
        } else {
            return mid;
        }
        this->binarySearch(A, start, end, target);
    }

    int searchUp(int A[], int pos, int n) {
        if (pos == -1) {
            return -1;
        }
        int v = A[pos];
        for (int i=pos; i<n; i++) {
            if (A[i] != v) {
                return i-1;
            }
        }
        return n-1;
    }

    int searchDown(int A[], int pos) {
        if (pos == -1) {
            return -1;
        }
        int v = A[pos];
        for (int i=pos; i>=0; i--) {
            if (A[i] != v) {
                return i+1;
            }
        }
        return 0;
    }

};
