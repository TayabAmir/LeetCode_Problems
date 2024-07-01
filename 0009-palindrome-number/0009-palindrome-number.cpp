class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x,digits=0;
        while(temp){
            digits++;
            temp /= 10;
        }
        temp = x;
        int i = 0, j = digits-1;
        while(i<j){
            int a = temp % 10;
            int b = (x / (int)pow(10,digits-i-1)) % 10;
            if(a != b) return false;
            temp /= 10,i++,j--;
        }
        return true;
    }
};