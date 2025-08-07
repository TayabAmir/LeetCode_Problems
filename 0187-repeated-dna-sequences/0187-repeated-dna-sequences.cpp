class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        unordered_map<string,int> mp;
        for(int i = 0; i < s.length()-9; i++){
            mp[s.substr(i, 10)]++;
        }
        vector<string> o = {};
        for(auto &pair : mp)
            if(pair.second > 1) o.push_back(pair.first);
        return o;
    }
};