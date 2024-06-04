class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=1;j<nums.size();)
        {
            if(nums[i] == 0 && nums[j] != 0)
                swap(nums[i],nums[j]);
            else if((nums[i] == 0 && nums[j] == 0)){
                j++;
                continue;
            }
            i++,j++;
        }
    }
};