class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0,end = nums.size()-1,count = 0;
        while(start < end)
        {
            if(nums[start]==val && nums[end] != val){
                swap(nums[start],nums[end]);
                start++,end--;
            }
            else if(nums[start]!=val)
                start++;
            else if(nums[end]==val)
                end--;
        }
        for(int ele: nums)
            if(ele == val)
                count++;
        return nums.size()-count;

    }
};