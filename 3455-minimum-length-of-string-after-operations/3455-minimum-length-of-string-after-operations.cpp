class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(char c : s) 
            freq[c-'a']++;

        int mL = s.length();
        for(int ele : freq)
            if(ele != 0)
                mL -= (ele % 2 == 1 ? ele-1 : ele-2); 
        return mL;
    }
};