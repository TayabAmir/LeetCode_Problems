class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() == k) return true;
        if(s.length() < k) return false;

        vector<int> freq(26, 0);
        for(char c : s)
            freq[c-'a']++;

        int count = 0;
        for(int ele : freq)
            if(ele % 2 == 1)
                count++;
        
        return count <= k;

    }
};