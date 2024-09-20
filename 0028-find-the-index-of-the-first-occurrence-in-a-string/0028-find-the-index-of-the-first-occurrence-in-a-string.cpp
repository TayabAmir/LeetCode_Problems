class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = haystack.length()-needle.length()+1;
        for(int i = 0; i < j; i++){
            if(haystack.substr(i, needle.length()) == needle) return i;}
        return -1;
    }
};