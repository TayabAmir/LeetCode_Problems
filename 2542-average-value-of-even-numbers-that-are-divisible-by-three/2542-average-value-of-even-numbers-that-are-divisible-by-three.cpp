class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(int ele : nums)
            if(ele % 6 == 0)
                sum += ele, count++;
        return count != 0 ? sum / count : 0; 
    }
};