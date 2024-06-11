class Solution {
public:
    int tribonacci(int n) {
        int F[38] = {0,1,1};
        for(int i=3;i<38;i++)
            F[i] = F[i-1] + F[i-2] + F[i-3];
        return F[n];
    }
};