class Solution {
public:
    int getNegative(vector<int>& nums) {
        int low = 0, high = nums.size() - 1,mid;
        while (low <= high) {
            mid = (high + low) / 2;
            if (mid < nums.size() - 2 && nums[mid] < 0 && nums[mid + 1] >= 0)
                return mid+1;
            else if (mid >= 1 && nums[mid] >= 0 && nums[mid - 1] < 0)
                return mid;
            if (nums[mid] >= 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    int getPositive(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (mid < nums.size() - 2 && nums[mid] <= 0 && nums[mid + 1] > 0)
                return nums.size()-mid-1;
            else if (mid >= 1 && nums[mid] > 0 && nums[mid - 1] <= 0)
                return nums.size()-mid;
            if (nums[mid] > 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return (high == -1) ? nums.size() : 0;
    }
    int maximumCount(vector<int>& nums) {
        if(nums.size()==1 && nums[0] != 0) return 1;
        if(nums.size()==1 && nums[0] == 0) return 0;
        return max(getPositive(nums),getNegative(nums));
    }
};