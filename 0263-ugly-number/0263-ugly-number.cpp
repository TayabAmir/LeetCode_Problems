class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false; 
        while (n % 2 == 0) {
            n /= 2;
        }
        for (int i = 3; i <= n; i += 2) { 
           if(i>5)
                return false;
            while (n % i == 0) {
               n /= i;
           }
        }
        return true;
    }
};