class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, len = 0;
        vector<int> freq(26, 0);
        function<int()> sum = [&]()->int{
            int a = 0;
            for(int ele : freq) a += ele;
            return a;
        };
        while(r < s.size()){
            freq[s[r]-'A']++;
            int maxi = *max_element(freq.begin(), freq.end());
            int left = sum() - maxi;
            if(left > k) freq[s[l]-'A']--, l++;
            else len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};