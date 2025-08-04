class Solution {
public:
    bool closeStrings(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> a(26, 0), b(26, 0);
        for(char c : s) a[c-'a']++;
        for(char c : t) b[c-'a']++;

        for(int i = 0; i < 26; i++)
            if((a[i] > 0 && b[i] == 0) || (a[i] > 0 && b[i] == 0)) return false;

        unordered_map<int,int> mp;
        for(int ele : a) mp[ele]++;
        for(int ele : b) mp[ele]--;

        for(auto &val : mp)
            if(val.second != 0) return false;
        return true;
    }
};