class Solution {
public:
    int p(int e){
        return e * (e + 1) / 2;
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> dp(p(n), -1);
        dp[0] = a[0][0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                dp[p(i) + j] = min((j <= i-1) ? a[i][j]+dp[p(i-1)+j] : INT_MAX, (j-1 >= 0) ? a[i][j]+dp[p(i-1)+(j-1)] : INT_MAX);
            }
        }
        return *min_element(dp.begin()+p(n-1), dp.end());
    }
};