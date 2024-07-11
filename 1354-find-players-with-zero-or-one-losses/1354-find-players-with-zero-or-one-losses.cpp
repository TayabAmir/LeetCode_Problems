class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        vector<bool> arr(1e5+1,true);
        for (int i = 0; i < matches.size(); i++) {
            m[matches[i][1]]++;
        }
        vector<int> winners, losers;
        for (int i = 0; i < matches.size(); i++) {
            int x = matches[i][0];
            if (m.find(x) == m.end() && arr[x]) {
                winners.push_back(x);
                arr[x] = false;
            }
        }
        for (const auto& [key, value] : m) {
            if (value == 1) {
                losers.push_back(key);
            }
        }
        sort(winners.begin(), winners.end());
        sort(losers.begin(), losers.end());
        
        return {winners, losers};
    }
};