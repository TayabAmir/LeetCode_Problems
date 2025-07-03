class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1, o = 0; 
        for(int i = 0; i < s.length(); ++i){
            (s[i] == 'a') ? a = i : (s[i] == 'b') ? b = i : c = i; 
            if(a != -1 && b != -1 && c != -1){
                o += (min({a,b,c})+1);
            }
        }
        return o;
    }
};