/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 bool comp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
}

class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), comp);

        vector<Interval> r;
        for (int i=0; i<intervals.size(); i++) {
            Interval current = intervals[i];

            if (r.size() == 0) {
                r.push_back(current);
            } else {
                Interval last = r.back();
                if (last.end >= current.start && last.end <= current.end) {
                    r.pop_back();
                    last.end = current.end;
                    r.push_back(last);
                } else if (last.end < current.start) {
                    r.push_back(current);
                }
            }
        }

        return r;
    }
};
