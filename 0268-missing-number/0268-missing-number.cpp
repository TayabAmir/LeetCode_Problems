class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sumofArr = 0;
        for(int i=0;i<nums.size();i++){
            sumofArr += i;
            sumofArr -= nums[i];
        }
        return sumofArr+nums.size();
    }
};