class Solution {
public:
    bool isPowerOfThree(int n) {
        long long curr = 1;
        while(curr <= n){
            if(curr == n) return true;
            curr *= 3;
        }
        return false;
    }
};