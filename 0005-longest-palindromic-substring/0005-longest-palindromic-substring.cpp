class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxi = "";
        function<string(int,int)> getPalin = [&](int l, int r) -> string {
            while(l >= 0 && r < n && s[l] == s[r]){
                l--, r++;
            }
            return s.substr(l+1, r-l-1);
        };

        for(int i = 0; i < n; ++i){
            string even = getPalin(i, i+1), odd = getPalin(i, i);
            if(even.size() > maxi.size()) maxi = even;
            if(odd.size() > maxi.size()) maxi = odd;
        }
        return maxi;
    }
};