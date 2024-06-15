class Solution {
public:
    int minimizedStringLength(string s) {
        bool arr[26]={false};
        int c=0;
        for(int i=0;i<s.length();i++)
            if(!arr[s[i]-'a']){
                arr[s[i]-'a'] = true;
                c++;
            }
        return c;
    }
};