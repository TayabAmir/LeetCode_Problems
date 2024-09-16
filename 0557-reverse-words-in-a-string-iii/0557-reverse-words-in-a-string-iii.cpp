class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0, j = 0; i < s.size(); i = j+1, j = i){
            while(j < s.length() && s[j] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j);
        }
        return s;
    }
};