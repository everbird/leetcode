class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;

        for (int i=0; i<numRows; i++) {
            vector<int> line;
            if (i == 0) {
                line.push_back(1);
            } else {
                vector<int> pre = r.at(i-1);
                for (int j=0; j<i+1; j++) {
                    int tmp = this->getValue(pre, j-1) + this->getValue(pre, j);
                    line.push_back(tmp);
                }
            }
            r.push_back(line);
        }

        return r;
    }

    int getValue(vector<int> line, int index) {
        if (index < 0 || index > line.size() - 1) {
            return 0;
        }

        return line.at(index);
    }
};
