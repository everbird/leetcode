class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;
        map<string, bool> m;

        if (num.size() == 0) {
            return r;
        }

        sort(num.begin(), num.end());

        for (int i=0; i<num.size(); i++) {
            int j = i+1;
            int k = num.size() - 1;
            while (j < k) {
                int sum_two = num[i] + num[j];
                if (sum_two + num[k] > 0) {
                    k--;
                } else if (sum_two + num[k] < 0) {
                    j++;
                } else {
                    string id = this->getId(num[i], num[j], num[k]);
                    if (m[id]) {
                        j++;
                        k--;
                        continue;
                    }

                    vector<int> item;
                    item.push_back(num[i]);
                    item.push_back(num[j]);
                    item.push_back(num[k]);
                    r.push_back(item);
                    m[id] = true;
                    j++;
                    k--;
                    continue;
                }
            }
        }

        return r;
    }

    string getId(int a, int b, int c) {
        return to_string(a)+","+to_string(b)+","+to_string(c);
    }

};
