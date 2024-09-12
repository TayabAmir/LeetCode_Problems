class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> freq(25, false);
        for(char c : allowed) freq[c-'a'] = true;
        int consistentStrings = 0;
        for(string s : words){
            bool consistent = true;
            for(char c : s){
                if(!freq[c-'a']){
                    consistent = false;
                    break;
                }
            }
            if(consistent) consistentStrings++;
        }
        return consistentStrings;
    }
};