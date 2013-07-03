class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (nRows==1) {
            return s;
        }
        map<int, string> lines;
        for (int i=0; i<nRows; i++) {
            lines[i] = "";
        }

        int line_no = 0;
        bool down_flag = true;

        for (int i=0; i<s.size(); i++) {
            lines[line_no].append(1, s.at(i));
            if (line_no == nRows-1 || line_no == 0) {
                if (i != 0) {
                    down_flag = !down_flag;
                }
            }

            if (down_flag) {
                line_no++;
            } else {
                line_no--;
            }
        }

        string r;
        for (int j=0; j<nRows; j++) {
            r += lines[j];
        }
        return r;
    }
};
