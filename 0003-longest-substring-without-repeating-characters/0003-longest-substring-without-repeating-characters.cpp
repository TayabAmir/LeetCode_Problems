class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        int maxi = 0;
        while(r < s.size()){
            if(mp.find(s[r]) != mp.end() && (l <= mp[s[r]] && mp[s[r]] <= r)){
                l = mp[s[r]]+1;
                mp[s[r]] = r;
            } else {
                mp[s[r]] = r;
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};