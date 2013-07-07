class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (*s == ' ') {
            s++;
        }

        if (*s == '+' || *s == '-') {
            s++;
        }

        if (*s == 'e') {
            return false;
        }

        if (*s == '.') {
            const char *dotnext = s+1;
            if (*dotnext == 'e') {
                return false;
            }
        }

        bool e_mode = false;
        bool dot_mode = false;
        bool tailing_blank = false;
        int count_after_e = 0;
        int count = 0;
        while (*s != '\0') {
            if (tailing_blank && *s != ' ') {
                return false;
            }

            if (*s < '0' || *s > '9') {
                if (*s == '.') {
                    if (dot_mode || e_mode) {
                        return false;
                    } else {
                        dot_mode = true;
                    }
                } else if (*s == 'e') {
                    if (e_mode) {
                        return false;
                    } else {
                        e_mode = true;
                        const char *next = s + 1;
                        if (*next == '+' || *next == '-') {
                            s += 2;
                            continue;
                        }
                    }
                } else if (*s == ' ') {
                    tailing_blank = true;
                } else {
                    return false;
                }
            }

            if (*s >= '0' && *s <= '9') {
                count++;
                if (e_mode) {
                    count_after_e++;
                }
            }

            s++;
        }

        return true && count != 0 && (!e_mode || (e_mode && count_after_e > 0));
    }

};
