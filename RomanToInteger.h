class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;

        int index = 0;
        int num = 0;

        while (index < s.size()) {
            int next = index + 1;
            if (next < s.size()) {
                int next_value = m[s.at(next)];
                int this_value = m[s.at(index)];
                if (next_value <= this_value) {
                    num += this_value;
                } else {
                    num += next_value - this_value;
                    index += 2;
                    continue;
                }
            } else {
                num += m[s.at(index)];
            }
            index++;
        }

        return num;
    }
};
