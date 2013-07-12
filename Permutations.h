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
            vector<int> t = this->push_front(result[i], back);
            r.push_back(t);
            for (int j=0; j<result[i].size(); j++) {
                vector<int> x = result[i];
                x = this->insert(x, j, back);
                r.push_back(x);
            }
        }
        return r;
    }

    vector<int> push_front(vector<int> &v, int i) {
        vector<int> r;
        r.push_back(i);
        for (int i=0; i<v.size(); i++) {
            r.push_back(v[i]);
        }
        return r;
    }

    vector<int> insert(vector<int> &v, int pos, int item) {
        vector<int> r;
        for (int i=0; i<v.size(); i++) {
            r.push_back(v[i]);
            if (i == pos) {
                r.push_back(item);
            }
        }
        return r;
    }
};
