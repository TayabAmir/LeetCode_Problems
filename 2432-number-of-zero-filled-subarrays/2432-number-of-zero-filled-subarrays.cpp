class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long res = 0;
        for(int ele : nums){
            if(ele == 0)
                count++;
            else if(count > 0){
                res += (count * (count+1))/2;
                count = 0;
            }
        }
        return (count > 0) ?  res + (count * (count+1))/2 : res;
    }
};