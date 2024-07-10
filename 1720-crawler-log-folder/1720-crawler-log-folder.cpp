class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;
        for(string s : logs){
            if(ops > 0 && s == "../")
                ops--;
            else if(s != "./" && s != "../")
                ops++;
        }
        return ops < 0 ? 0 : ops;
    }
};