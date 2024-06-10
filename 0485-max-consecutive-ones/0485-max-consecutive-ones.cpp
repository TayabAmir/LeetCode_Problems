class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = INT_MIN,ones=0;
        for(int ele : nums)
            if(ele == 1)
                ones++;
            else{
                maxOnes = max(maxOnes,ones);
                ones=0;    
            }
        return max(maxOnes,ones);
    }
};