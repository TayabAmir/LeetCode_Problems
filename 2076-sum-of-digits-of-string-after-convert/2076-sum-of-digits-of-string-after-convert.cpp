class Solution {
public:
    string transform(string s){
        int sum = 0;
        for(char c : s){
            sum += (c - '0');
        }
        return to_string(sum);
    }
    int getLucky(string s, int k) {
        string num = "";
        for(char c : s){
            int ch = c - 'a' + 1;
            if(ch > 9)
                num += (ch/10 + '0');
            num += (ch % 10 + '0'); 
        }
        while(k--){
            num = transform(num);
        }
        return stoi(num);
    }
};