class Solution {
public:
    char next(char c){
        if(c == 'z') return 'a';
        return c+1;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(i < str1.length()){
            if(str1[i] == str2[j] || next(str1[i]) == str2[j])
                j++;
            i++;
        }
        return j == str2.length();
    }
};