class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0) {
            return 1.0 / (this->pow(x, -(n+1)) * x);
        }

        if (n == 0) {
            return 1;
        }

        if (x == 0) {
            return 0;
        }

        double r = 1;
        double t = x;
        int index = 0;

        while (n != 0) {
            if (index == 0) {
                t = x;
            } else {
                t *= t;
            }
            if (n % 2 == 1) {
                r *= t;
            }

            n /= 2;
            index++;
        }

        return r;
    }
};
