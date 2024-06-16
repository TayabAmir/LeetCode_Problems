class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            vector<bool> rows(n+1,false);
            vector<bool> cols(n+1,false);
            for(int j=0;j<n;j++){
                rows[matrix[i][j]] = true;
                cols[matrix[j][i]] = true;
            }
            for(int i=1;i<n+1;i++){
                if(!rows[i] || !cols[i])
                    return false;
            }
        }
        return true;
    }
};