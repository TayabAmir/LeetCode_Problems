class Solution {
public:
    bool isPerfectSquare(int num) {
        double ans = pow(num,0.5);
        return ans == (int)ans;  
    }
};