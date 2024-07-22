class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if((nums[low] < nums[high]) || nums.size()==1) return nums[0];
        while(low <= high){
            int mid = (high + low) / 2;
            if((mid < nums.size() - 1) && nums[mid] > nums[mid+1]) return nums[mid+1];
            if(mid > 0 && nums[mid] < nums[mid-1]) return nums[mid];
            if(nums[mid] >= nums[low]) low = mid + 1;
            else  high = mid - 1;
        }
        return nums[low];
    }
};