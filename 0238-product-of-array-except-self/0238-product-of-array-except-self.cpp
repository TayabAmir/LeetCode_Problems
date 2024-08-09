class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),product = 1,zeroCount = 0, idx = -1;
        vector<int> output(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                product *= nums[i];
            else{
                ++zeroCount,idx = i;
            }
        }
            if(zeroCount == 1) output[idx] = product;
            else if(zeroCount > 1) return output;
            else {
                for(int i = 0; i < n; i++)
                    output[i] = product/nums[i];
            }
        return output;
    }
};