class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        int start = a[0][0];
        int end = a[0][1];
        for(int i = 1; i < a.size(); ++i){
            if(a[i][0] <= end){
                end = max(end, a[i][1]);
            } else{
                res.push_back({start, end});
                start = a[i][0], end = a[i][1];
            }
        }
        res.push_back({start, end});

        return res;
    }
};