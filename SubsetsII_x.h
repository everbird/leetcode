class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;

        if (S.size() == 1) {
            vector<int> empty;
            r.push_back(empty);
            r.push_back(S);
            return r;
        }

        int last = S.back();
        S.pop_back();
        vector<vector<int>> r1 = this->subsetsWithDup(S);

        for (int i=0; i<r1.size(); i++) {
            vector<int> t = r1[i];
            t.push_back(last);
            if (!this->isInVector(t, r1)) {
                r1.push_back(t);
            }
        }
        return r1;
    }

    bool isInVector(vector<int> &a, vector<vector<int>> &S) {
        for (int i=0; i<S.size(); i++) {
            if (this->isVectorEquals(a, S[i])) {
                return true;
            }
        }
        return false;
    }

    bool isVectorEquals(vector<int> &a, vector<int> &b) {
        if (a.size() != b.size()) {
            return false;
        }

        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;

    }
};
