class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0,end = sqrt(c);
        while(start <= end){
            long sum = (start * start) + (end * end);
            if(sum == c) return true;
            if(sum < c) start++;
            else if(sum > c) end--;
        }
        return false;
    }
};