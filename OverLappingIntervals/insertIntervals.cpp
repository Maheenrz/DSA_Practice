class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        // adding new intervals to intervals                        
        intervals.push_back(newInterval);

        //now sorting them
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> non_overlap;
        vector<int> current = intervals[0];
        //making them non overlapped
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                non_overlap.push_back(current);
                current = intervals[i];
            }
        }
        // return final intervals
        non_overlap.push_back(current);
        return non_overlap;
    }
};