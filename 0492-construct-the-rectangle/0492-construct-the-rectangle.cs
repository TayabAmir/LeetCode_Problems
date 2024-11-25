public class Solution {
    public int[] ConstructRectangle(int area) {
        int length = -1, width = -1;
        for(int i = 1; i <= Math.Sqrt(area); i++){
            if(area % i == 0){
                int divisor = i, dividend = area / i;
                if(length == -1 || (Math.Abs(dividend - divisor) < Math.Abs(length - width))){
                    length = dividend; 
                    width = divisor;
                }
            }
        }
        int[] arr = new int[2]{length, width};
        return arr;
    }
}