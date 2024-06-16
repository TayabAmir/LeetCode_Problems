class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string output = "1";
        for (int i = 1; i < n; ++i) {
            output = helper(output);
        }
        return output;
    }
    string helper(string s){
        string output = "";
        for(int i=0;i<s.length();){
            int count = 0;
            char c = s[i];
            while(i<s.length() && s[i] == c) 
                count++,i++;
            output += to_string(count);
            output += c;
        }
        return output;
    }
};