class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int zero_count = 0;
        string r = "0";
        for (int i=num1.size()-1; i>=0; i--) {
            string x = this->multiply_one_int(num2, num1[i] - '0');
            for (int z=0; z<zero_count; z++) {
                x += "0";
            }
            zero_count++;
            r = this->add(r, x);
        }

        return r;
    }

    string add(string num1, string num2) {
        if (num1 == "0") {
            return num2;
        }

        if (num2 == "0") {
            return num1;
        }

        string r ="";
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int extra = 0;

        while (index1 > -1 || index2 > -1) {
            int i1 = index1==-1? 0: num1[index1] - '0';
            int i2 = index2==-1? 0: num2[index2] - '0';

            int value = i1 + i2 + extra;

            r = this->push_front(r, value % 10);
            extra = value / 10;
            if (index1 > -1) {
                index1--;
            }
            if (index2 > -1) {
                index2--;
            }
        }

        if (extra > 0) {
            r = this->push_front(r, extra);
        }

        return r;
    }

    string multiply_one_int(string &num, int n) {
        int extra = 0;
        string r = "";
        for (int i=num.size()-1; i>=0; i--) {
            int value = (num[i] - '0') * n + extra;
            r = this->push_front(r, value % 10);
            extra = value / 10;
        }

        if (extra > 0) {
            r = this->push_front(r, extra);
        }

        return r;
    }

    string push_front(string &num, int n) {
        return to_string(n) + num;
    }
};
