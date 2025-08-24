class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int l = 0, r = 0, maxi = 0;
        bool err = false;
        while(r < n){
            if(!a[r]){
                if(err){
                    cout << l << " " << r << endl;
                    maxi = max(maxi, r-l);
                    while(l < r && a[l]) l++;
                    l++, r--;
                    err = false;
                } else err = true;
            }
            r++;
        }
        return max(maxi, r-l) - 1;
    }
};