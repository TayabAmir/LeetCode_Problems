class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int m = -1,n = -1;
        for(int i=0, j=nums.size()-1;m == -1 || n == -1;){
            if(isPrime(nums[i]))
                m = i;
            else i++;
            if(isPrime(nums[j]))
                n = j;
            else j--;
        }
        return abs(m-n);
    }
};