class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        function<void(int,int)> getPalin = [&](int l, int r) -> void {
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--, r++;
            }
        };

        for(int i = 0; i < n; ++i){
            getPalin(i, i+1);
            getPalin(i, i);
        }
        return count;
    }
};