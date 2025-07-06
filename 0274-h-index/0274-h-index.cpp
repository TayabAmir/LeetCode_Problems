class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size(), o = 0, maxi = c[n-1];

        function<int(int)> bin = [&](int h) -> int {
            int l = 0, r = c.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                (c[m] < h) ? l = m + 1 : r = m;
            }
            return l;
        };

        for(int i = 0; i <= maxi; i++){
            int co = n - bin(i);
            if(i == min(co,i) && i > o) o = i;
        }
        return o;
    }
};