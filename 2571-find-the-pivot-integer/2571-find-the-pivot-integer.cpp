class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n * (n+1)) / 2,temp = 0,x = 1;
        while(n--){
            sum -= x;
            if(sum == temp) return x;
            temp += x;
            x++;
        }
        return -1;
    }
};