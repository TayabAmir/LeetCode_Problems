class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); ++i)
            arr[i] = arr[i-1] ^ arr[i];
        vector<int> ans;
        for(auto q : queries)
            (q[0] == 0) ? ans.push_back(arr[q[1]]) : ans.push_back(arr[q[0]-1] ^ arr[q[1]]);
        return ans;
    }
};