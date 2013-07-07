class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) {
            return "";
        }
        int min_length = pow(2, 31) - 1;
        for (int i=0; i<strs.size(); i++) {
            int _length = strs[i].size();
            if (min_length > _length) {
                min_length = _length;
            }
        }

        string common = "";
        for (int i=0; i<min_length; i++) {
            char x = strs[0][i];
            for (int j=0; j<strs.size(); j++) {
                if (x != strs[j][i]) {
                    return common;
                }
            }
            common+=strs[0][i];
        }
        return common;
    }
};
