class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;

        int o = 0, e = INT_MAX;
        for(int ele : freq){
            if(ele != 0)
            if(ele & 1) o = max(o, ele);
            else e = min(e, ele);
        }

        return o - e;
    }
};