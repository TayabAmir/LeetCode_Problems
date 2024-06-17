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
        int m = -1,n = -1,i = 0, j = nums.size()-1;
        while(m == -1){
            if(isPrime(nums[i]))
                m = i;
            i++;
        }
        while(n == -1){
            if(isPrime(nums[j]))
                n = j;
            j--;
        }
        return abs(m-n);
    }
};