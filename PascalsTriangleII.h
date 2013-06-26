class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r;

        for (int i=0; i<=rowIndex; i++) {
            vector<int> line;
            if (i == 0) {
                line.push_back(1);
            } else {
                for (int j=0; j<i+1; j++) {
                    int tmp = this->getValue(r, j-1) + this->getValue(r, j);
                    line.push_back(tmp);
                }
            }

            r = line;
        }

        return r;
    }

    int getValue(vector<int> line, int index) {
        if (index < 0 || index > line.size() -1) {
            return 0;
        }
        return line.at(index);
    }
};
