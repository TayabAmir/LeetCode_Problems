struct comp {
    bool operator()(pair<int, string>& a,pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string s : words) mp[s]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto pair : mp)
            pq.push({pair.second, pair.first});

        vector<string> res;
        while(k--)
            res.push_back(pq.top().second), pq.pop();
        return res;
    }
};