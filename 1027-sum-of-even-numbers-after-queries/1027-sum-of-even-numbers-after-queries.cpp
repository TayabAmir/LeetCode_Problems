class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for(auto v : queries){
            nums[v[1]] += v[0];
            int sum = 0;
            for(int i : nums)
                if(i % 2 == 0) sum += i;
            ans.push_back(sum);
        }
        return ans;
    }
};