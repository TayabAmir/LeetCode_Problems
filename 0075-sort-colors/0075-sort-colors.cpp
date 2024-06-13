class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0,ones=0;
        for(int ele : nums)
            if(ele == 0) zeros++;
            else if(ele == 1) ones++;
        int twos = nums.size() - (zeros + ones);
        for(int i=0;i<nums.size();){
            while(zeros--) nums[i++] = 0;
            while(ones--) nums[i++] = 1;
            while(twos--) nums[i++] = 2;
        }
    }
};