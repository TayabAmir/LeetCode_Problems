struct Comp {
    static bool operator()(pair<char,int> &a, pair<char,int> &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, Comp> pq;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                s[pq.top().second] = ';';
                pq.pop();
            } else pq.push({s[i], i});
        }

        string ans = "";
        for(char &c : s){
            if(c != ';' && c != '*') ans += c;
        }
        return ans;
    }
};