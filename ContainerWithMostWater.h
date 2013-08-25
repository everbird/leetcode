class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int m = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            m = max(area, m);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return m;
    }
};
