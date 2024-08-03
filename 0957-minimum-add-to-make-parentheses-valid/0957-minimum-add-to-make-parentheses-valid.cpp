class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0, closeCount = 0;
        for(char c : s){
            if(c == '('){
                openCount++;
            } else if(c == ')' && openCount > 0){
                openCount--;
            } else if(c == ')' && openCount <= 0){
                closeCount++;
            }
        }
        return openCount + closeCount;
    }
};