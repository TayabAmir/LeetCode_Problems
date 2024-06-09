class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),product = 1,zeroCount = 0;
        vector<int> output;
        for(int ele : nums){
            if(ele != 0)
                product *= ele;
            else
                ++zeroCount;
        }for(int ele : nums){
            if(ele !=0)
                if(zeroCount == 0)
                    output.push_back(product/ele);
                else
                    output.push_back(0);
            else if(zeroCount == 1)
                output.push_back(product);
            else if(zeroCount > 1)
                output.push_back(0);
        }
        return output;
    }
};