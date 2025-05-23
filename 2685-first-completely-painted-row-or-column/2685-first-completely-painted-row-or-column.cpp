class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int,int>> mp;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                mp[mat[i][j]] = {i, j};
        
        vector<int> rows(m, 0), cols(n, 0);
        for(int i = 0; i < arr.size(); i++){
            auto p = mp[arr[i]];
            rows[p.first]++, cols[p.second]++;
            if(rows[p.first] == n || cols[p.second] == m) return i;
        }
        return -1;

    }
};