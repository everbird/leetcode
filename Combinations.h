class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;
        if (n < k) {
            return r;
        }

        if (n==1) {
            vector<int> tmp;
            tmp.push_back(1);
            r.push_back(tmp);
            return r;
        }

        if (k==1) {
            for (int i=1; i<=n; i++) {
                vector<int> x;
                x.push_back(i);
                r.push_back(x);
            }

            return r;
        }

        vector<vector<int>> r1 = this->combine(n-1, k-1);
        vector<vector<int>> r2 = this->combine(n-1, k);
        for (int i=0; i<r1.size(); i++) {
            vector<int> t = r1[i];
            t.push_back(n);
            r2.push_back(t);
        }
        return r2;
    }
};
