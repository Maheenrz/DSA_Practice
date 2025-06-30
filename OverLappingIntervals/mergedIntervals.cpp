class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort intervals by start time

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<int> current = intervals[0];
        vector<vector<int>> merged;

        //[a,b] & [c,d] if c≤b merge them
        for (int i = 1; i < intervals.size(); i++) {
            // interval[0] is start, interval[1] is end
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                merged.push_back(current);
                current = intervals[i];
            }
        }
        //merge remaining vector
        merged.push_back(current);

        return merged;
    }
};