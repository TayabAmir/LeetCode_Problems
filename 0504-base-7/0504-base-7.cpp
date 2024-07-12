class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int n = abs(num);
        string base7 = "";
        while(n > 0){
            base7 = to_string(n % 7) + base7;
            n /= 7;
        }
        return (num < 0) ? "-" + base7 : base7;
    }
};