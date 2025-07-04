class MyCalendarTwo {
private:
    vector<pair<int, int>> all_bookings;
    vector<pair<int, int>> overlapped;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        if (all_bookings.empty()) {
            all_bookings.push_back({startTime, endTime});
        }

        if (all_bookings.size() == 1) {
            if (all_bookings[0].second >= startTime) {
                overlapped.push_back({startTime, endTime});
                overlapped.push_back(all_bookings[0]);
            }
        } else {
            sort(overlapped.begin(), overlapped.end());

            for (const auto& over_lap : overlapped) {
                if (over_lap.second >= startTime) {
                    return false;
                }
            }
        }

        all_bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */