class Solution {
public:
    vector<vector<int>> cache;

    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->cache.clear();

        int width = grid[0].size();
        int height = grid.size();
        for (int i=0; i<height; i++) {
            vector<int> t;
            for (int j=0; j<width; j++) {
                t.push_back(0);
            }
            this->cache.push_back(t);
        }
        return this->find(grid, width-1, height-1);
    }

    int find(vector<vector<int>> &grid, int x, int y) {
        if (this->cache[y][x] != 0) {
            return this->cache[y][x];
        }

        if (x == 0 && y == 0) {
            this->cache[y][x] = grid[y][x];
            return grid[y][x];
        }

        if (x == 0) {
            int value1 = this->find(grid, x, y-1) + grid[y][x];
            this->cache[y][x] = value1;
            return value1;
        }

        if (y == 0) {
            int value2 = this->find(grid, x-1, y) + grid[y][x];
            this->cache[y][x] = value2;
            return value2;
        }

        int sum_a = this->find(grid, x-1, y);
        int sum_b = this->find(grid, x, y-1);
        int min = sum_a;
        if (sum_b < min) {
            min = sum_b;
        }
        this->cache[y][x] = min + grid[y][x];
        return min + grid[y][x];
    }
};
