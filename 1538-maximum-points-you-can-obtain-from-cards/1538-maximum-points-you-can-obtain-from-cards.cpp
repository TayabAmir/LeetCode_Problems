class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum = 0, n = a.size();
        for(int i = 0; i < k; i++) sum += a[i];

        if(k == n) return sum;
        int maxi = sum, r = n - 1;
        for(int i = k - 1; i >= 0; i--)
            sum += (a[r]-a[i]), r--, maxi = max(maxi,sum);
        return maxi;
    }
};