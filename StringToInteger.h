class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int max_int = pow(2, 31) - 1;
        int min_int = -pow(2, 31);

        while (str[0] == ' ') {
            str++;
        }

        if (str == NULL) {
            return 0;
        }

        int flag_positive = 1;
        bool overflow = false;

        if (str[0] == '-') {
            flag_positive = -1;
            ++str;
        } else if (str[0] == '+') {
            ++str;
        }

        double r = 0;
        int length = strlen(str);

        for (int i=0; i<strlen(str); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                int tmp = r;
                r = r * 10 + (str[i] - '0');
                if (r > max_int) {
                    overflow = true;
                    break;
                }

            } else {
                break;
            }
        }

        if (overflow) {
            return flag_positive==1? max_int: min_int;
        }

        return flag_positive*r;
    }
};
