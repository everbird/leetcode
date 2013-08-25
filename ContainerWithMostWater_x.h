class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int m = 0;

        for (int i=0; i<height.size(); i++) {
            if (i > 0 && height[i]< height[i-1]) {
                continue;
            }
            for (int j=i+1; j<height.size(); j++) {
                if (j+1<height.size() && height[j] < height[j+1] || m / (j - i) > height[j]) {
                    continue;
                }
                int area = (j - i) * min(height[i], height[j]);
                m = max(m, area);
            }
        }

        return m;
    }
};
