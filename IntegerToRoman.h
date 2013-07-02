class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        string symbol[7] = {"I","V","X", "L","C", "D","M"};
        int scale = 1000;
        for (int i=6; i>=0; i-=2) {
            int digit = num / scale;
            if (digit <= 3) {
                for (int j=0; j<digit; j++) {
                    result += symbol[i];
                }
            } else if (digit == 4) {
                result += symbol[i] + symbol[i+1];
            } else if (digit <= 8) {
                result += symbol[i+1];
                for (int j=0; j<digit-5; j++) {
                    result += symbol[i];
                }
            } else if (digit == 9) {
                result += symbol[i] + symbol[i+2];
            }
            num %= scale;
            scale /= 10;
        }
        return result;
    }
};
