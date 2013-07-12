class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return this->dp(num, num.size()-1);
    }

    vector<vector<int>> dp(vector<int> &num, int limit) {
        vector<vector<int>> r;

        if (limit == 0) {
            vector<int> tmp;
            tmp.push_back(num[0]);
            r.push_back(tmp);
            return r;
        }

        int back = num.back();
        num.pop_back();

        vector<vector<int>> result = this->dp(num, limit-1);
        for (int i=0; i<result.size(); i++) {
            vector<int> x = result[i];
            for (int j=0; j<=x.size(); j++) {
                x.insert(x.begin(), j, back);
                r.push_back(x);
            }
        }
        return r;
    }
};
