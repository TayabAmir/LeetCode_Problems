class Solution {
public:
    bool isVowel(char c){
        return c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u';
    }
    int beautifulSubstrings(string s, int m) {
        int b = 0;
        for(int i = 0;i < s.length(); i++){
                int vCount=0,cCount=0;
            for(int j = i; j < s.length(); j++){
                    (isVowel(s[j])) ? vCount++ : cCount++;
                if((vCount == cCount) && (vCount*cCount) % m == 0)
                    b++;
            }
        }
        return b;
    }
};