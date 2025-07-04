class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, len = 0, sum = 0, maxi = 0;
        vector<int> freq(26, 0);
        // function<int()> sum = [&]()->int{
        //     int a = 0;
        //     for(int ele : freq) a += ele;
        //     return a;
        // };
        while(r < s.size()){
            freq[s[r]-'A']++;
            sum += 1;
            maxi = max(maxi, freq[s[r]-'A']);
            int left = sum - maxi;
            if(left > k) freq[s[l]-'A']--, sum--, l++;
            else len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};