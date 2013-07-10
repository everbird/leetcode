class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        return this->dp(S, S.size() - 1);
    }

    vector<vector<int>> dp(vector<int> &S, int end) {
        if (end == 0) {
            vector<vector<int>> result;
            vector<int> empty;
            vector<int> item;
            item.push_back(S[0]);
            result.push_back(empty);
            result.push_back(item);
            return result;
        }

        vector<vector<int>> r = this->dp(S, end-1);
        vector<vector<int>> clone(r);
        for (int i=0; i<clone.size(); i++) {
            clone[i].push_back(S[end]);
            r.push_back(clone[i]);
        }
        return r;
    }
};
