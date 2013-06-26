class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int numRows = triangle.size();
        vector<int> last_line = triangle.back();
        int numColumns = last_line.size();
        int d[256][256];
        memset(d, 0, sizeof(d));
        for (int i=0; i<last_line.size(); i++) {
            d[numRows][i] = last_line.at(i);
        }

        this->getPathMinSumDP(triangle, d, numRows - 1);
        return d[0][0];
    }

    void getPathMinSumDP(vector<vector<int>> triangle, int d[256][256], int depth) {
        if (depth < 0) {
            return;
        }

        if (depth == triangle.size() - 1) {
            vector<int> t = triangle.at(depth);
            for (int i=0; i<t.size(); i++) {
                d[depth][i] = t.at(i);
            }
        } else if (depth < triangle.size() - 1) {
            int *next_line = d[depth + 1];
            vector<int> current_line = triangle.at(depth);

            for (int i=0; i<current_line.size(); i++) {
                int a = next_line[i];
                int b = next_line[i+1];
                int _i = i;
                if (a > b) {
                    _i = i + 1;
                }

                d[depth][i] = current_line.at(i) + d[depth+1][_i];
            }
        }

        if (depth > 0) {
            this->getPathMinSumDP(triangle, d, depth-1);
        }
    }
};
