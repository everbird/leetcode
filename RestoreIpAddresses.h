class Solution {
public:
    vector<string> result;

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->result.clear();
        this->checkIpAddress(s, "", 1);
        return this->result;
    }

    void checkIpAddress(string s, string prefix, int count) {
        if (s.size() == 0) {
            return;
        }

        if (count == 4) {
            if (s.size() < 4 && stoi(s) <= 255 && (s.size() == 1 || s.substr(0, 1) != "0")) {
                prefix += this->substr(s, 0, s.size());
                this->result.push_back(prefix);
            }
            return;
        }

        this->checkIpAddress(s.substr(1), prefix+this->substr(s, 0, 1)+".", count+1);

        if (s.size() > 1 && s.substr(0, 1) != "0") {
            this->checkIpAddress(s.substr(2), prefix+this->substr(s, 0, 2)+".", count+1);
        }

        if (s.size() > 2 && (s.substr(0, 1) != "0")) {
            int item = stoi(s.substr(0, 3));
            if (item >= 0 && item <= 255) {
                this->checkIpAddress(s.substr(3), prefix+this->substr(s, 0, 3)+".", count+1);
            }
        }

    }

    string substr(string s, int start, int length) {
        string x = s.substr(start, length);
        int t = stoi(x);
        return to_string(t);
    }
};
