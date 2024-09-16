class Solution {
public:
    static int hoursToMins(string a) {
        if(a == "00:00") return 1440;
        return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
    }
    // static bool comp(const string& a, const string& b) {
    //     return hoursToMins(a) < hoursToMins(b);
    // }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins(timePoints.size());
        for(int i = 0; i < timePoints.size(); ++i){
            mins[i] = hoursToMins(timePoints[i]); 
        }
        sort(mins.begin(), mins.end());
        int mini = INT_MAX;
        for(int i = 1; i < mins.size(); ++i){
            if(mins[i] - mins[i-1] < mini){
                mini = mins[i] - mins[i-1];
            }
        }
        return min(mini, abs(mins[mins.size()-1] - (1440+mins[0])));
    }
};