class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<string> result;
        vector<string> r = this->dp(n);
        sort(r.begin(), r.end());
        result.push_back(r[0]);
        for (int i=1; i<r.size(); i++) {
            if (r[i] != r[i-1]) {
                result.push_back(r[i]);
            }
        }
        return result;
    }

    vector<string> dp(int n) {
        vector<string> r;

        if (n == 1) {
            r.push_back("()");
            return r;
        }

        vector<string> results = this->dp(n-1);
        for (int i=0; i<results.size(); i++) {
            vector<string> items = this->insertParenthese(results[i]);
            for (int j=0; j<items.size(); j++) {
                r.push_back(items[j]);
            }
        }
        return r;
    }

    vector<string> insertParenthese(string origin) {
        vector<string> r;
        for (int i=0; i<origin.size(); i++) {
            if (origin[i] == '(' || i == origin.size() - 1) {
                string t = origin;
                t.insert(i+1, "()");
                r.push_back(t);
            }
        }
        return r;
    }
};
