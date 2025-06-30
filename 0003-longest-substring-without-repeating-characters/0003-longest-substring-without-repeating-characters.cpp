struct node {
    int freq;
    int lastOcc;
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        unordered_map<int, node> mp;
        int maxi = 0;
        while(r < s.size()){
            mp[s[r]].freq++;
            if(mp[s[r]].freq > 1 && (l <= mp[s[r]].lastOcc && mp[s[r]].lastOcc <= r)){
                l = mp[s[r]].lastOcc+1;
                mp[s[r]].freq = 1;
                mp[s[r]].lastOcc = r;
            } else {
                mp[s[r]].lastOcc = r;
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};