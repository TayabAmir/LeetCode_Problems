class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0,i = 0;
        while(i<nums.size()){
            nums[k++] = nums[i];
            int temp = nums[i];
            while(i < nums.size() && temp == nums[i])
                i++;
        }
        return k;
    }
};