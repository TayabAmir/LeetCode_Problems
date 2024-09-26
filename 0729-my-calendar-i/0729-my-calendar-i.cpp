class MyCalendar {
public:
    vector<pair<int, int>> calendar;

    bool book(int start, int end) {
        
        for (auto& pair : calendar) {
            if (max(pair.first, start) < min(pair.second, end)) {
                return false;
            }
        }
        calendar.push_back(make_pair(start, end));
        return true;
    }
};
