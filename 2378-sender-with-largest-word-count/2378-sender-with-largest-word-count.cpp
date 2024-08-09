class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        int k = 0;
        for(string message : messages){
            int spaces = 1;
            for(char c : message)
                if(c == ' ') spaces++;
            m[senders[k++]] += spaces;
        }
        int max = -1;
        string sender = "";
        for(auto pair : m){
            if(pair.second >= max){
                max = pair.second, sender = pair.first;
            }
        }
        return sender;
    }
};