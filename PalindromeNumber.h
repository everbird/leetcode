class Solution {
public:
    int length;

    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->length = this->intLength(x);

        return this->_isPalindrome(x);
    }

    bool _isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int length = this->length;
        if (x == 0 || length == 1) {
            return true;
        }

        int head_dight = x / pow(10, length - 1);
        int tail_dight = x % 10;

        if (head_dight != tail_dight) {
            return false;
        }

        x = x % (int)pow(10, length - 1);
        x /= 10;
        this->length -= 2;

        return this->_isPalindrome(x);
    }

    int intLength(int x) {
        if (x == 0) {
            return 1;
        }

        int length = 0;
        while (x != 0) {
            x /= 10;
            length++;
        }
        return length;
    }
};
