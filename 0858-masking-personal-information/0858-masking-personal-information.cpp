class Solution {
public:
    string lower(string s){
        for(int i=0;i<s.length();i++)
            s[i] = tolower(s[i]);
        return s;
    }
    string getDigits(string s){
        string res = "";
        for(char c: s){
            if(c >= '0' && c <= '9'){
                res += c;
            } 
        }
        return res;
    }
    string maskPII(string s) {
        size_t email = s.find('@');
        string res = "";
        if(email != string::npos){
            s = lower(s),res="*****";
            res=string(1,s[0])+res+string(1,s[email-1])+'@'+ s.substr(email+1, s.size()-email+1);
        }
        else{
            s = getDigits(s);
            res="***-***-"+s.substr(s.length()-4);
            if(s.length() == 11)
                res = "+*-" + res;
            else if(s.length() == 12)
                res = "+**-" + res;
            else if(s.length() == 13)
                res = "+***-" + res;
        }
        return res;
    }
};