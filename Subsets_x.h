class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;

        vector<int> empty;
        r.push_back(empty);

        sort(S.begin(), S.end());

        int length = 1;
        int end = 0;
        while (length <= S.size()) {
            end = S.size() - length + 1;
            for (int i=0; i<end; i++) {
                r.push_back(this->subvector(S, i, i+length));
            }
            length++;
        }

        return r;
    }

    vector<int> subvector(vector<int> &S, int start, int end) {
        vector<int> r;
        for (int i=0; i<S.size(); i++) {
            if (i >= start && i < end) {
                r.push_back(S[i]);
            }
        }
        return r;
    }
};
