class Solution {
public:
    long long C(int n, int r) {
        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int j = 0; j <= rowIndex; j++){
            ans.push_back(C(rowIndex,j));
        }
        return ans;
    }
};