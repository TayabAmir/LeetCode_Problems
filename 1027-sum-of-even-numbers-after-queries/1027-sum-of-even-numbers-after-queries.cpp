class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int i : nums) if(i % 2 == 0) sum += i;
        for(auto v : queries){
            if(nums[v[1]] % 2 == 0) sum -= nums[v[1]];
            nums[v[1]] += v[0];
            if(nums[v[1]] % 2 == 0) sum += nums[v[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};