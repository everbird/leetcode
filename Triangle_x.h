class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return this->getPathMinSum(triangle, 0, 0);
    }

    int getPathMinSum(vector<vector<int>> triangle, int index, int depth) {
        if (depth > triangle.size() - 1) {
            return 0;
        }

        int left = this->getPathMinSum(triangle, index, depth+1);
        int right = this->getPathMinSum(triangle, index+1, depth+1);
        int min = left;
        if (right < left) {
            min = right;
        }

        return min + triangle.at(depth).at(index);
    }
};
