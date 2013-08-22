class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // Ref: http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
        // Another O(n) time, O(1) space solution is here:
        // http://discuss.leetcode.com/questions/270/unique-binary-search-trees#answer-container-785
        if (n == 0 || n == 1) {
            return 1;
        }

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += this->numTrees(i) * this->numTrees(n - 1 - i);
        }
        return sum;
    }
};
