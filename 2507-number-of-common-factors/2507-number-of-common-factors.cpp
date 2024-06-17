class Solution {
public:
    int commonFactors(int a, int b) {
        int factors = 1, n = min(a,b);
        for(int x = 2; x <= n; x++)
            if(a % x == 0 && b % x == 0)
                factors++;
        return factors;
    }
};