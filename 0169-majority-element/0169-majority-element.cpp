class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;
        for(int i=0; i<nums.size();i++){
            if(count == 0){
                candidate = nums[i];
                count=1;
            }
            else if(candidate == nums[i])    count++;
            else count--;
        }
        // int c=0;
        // for(int ele : nums)
        //     if(ele == candidate)
        //         c++;
        // if(c)
        return candidate;
    }
};