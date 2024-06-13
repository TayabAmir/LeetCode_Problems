class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i <= pow(num,0.5); i++){
            if(i*i==num) return true;
            else if(i*i>num) break;
        }
    return false;  
    }
};