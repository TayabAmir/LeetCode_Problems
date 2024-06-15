class Solution {
public:
    int secondHighest(string s) {
        int largest = -1,sLargest = -1;
        for(char c : s){
            if(c >= '0' && c <= '9'){
                int n = c - 48;
                if(n > largest){
                    sLargest = largest;
                    largest = n;
                }
                else if(n > sLargest && n != largest)
                    sLargest = n;
            }
        }
        return sLargest;
    }
};