class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string t = "";
        for (string &s : strs) {
            t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto &pair : mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};