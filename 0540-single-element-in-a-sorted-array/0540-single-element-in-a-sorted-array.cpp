class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid == 0 || mid == nums.size()-1)
                return nums[mid]; 
            if(nums[mid] == nums[mid+1]){
                if(mid % 2 == 0){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else if(nums[mid] == nums[mid-1]){
                if((mid-1) % 2 == 1){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};