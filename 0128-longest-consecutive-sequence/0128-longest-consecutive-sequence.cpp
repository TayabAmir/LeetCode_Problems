class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.resize(nums.size()+1);
        nums[nums.size()-1] = -1e9-1;
        int count=0,maxCount = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]+1 == nums[i+1])
                count++;
            else if(nums[i] == nums[i+1])
                continue;
            else{
                count++;
                maxCount = max(maxCount,count);
                count = 0;
            }
        }
        return maxCount;
    }
};