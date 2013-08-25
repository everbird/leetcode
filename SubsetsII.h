class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > r;
        vector<int> path;
        sort(S.begin(), S.end());
        this->sub(S, r, 0, path);
        return r;
    }

    void sub(vector<int> &s, vector<vector<int>> &r, int start, vector<int> &path) {
        r.push_back(path);
        for (int i=start; i<s.size(); i++) {
            if (i != start && s[i] == s[i-1]) {
                continue;
            }

            path.push_back(s[i]);
            this->sub(s, r, i+1, path);
            path.pop_back();
        }
    }
};
