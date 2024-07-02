class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        multimap<int,char,greater<int>> m2;
        for(char c : s)
            m[c]++;
        for(auto p : m)
            m2.insert({p.second,p.first});
        s = "";
        for(auto p : m2){
            int a = p.first;
            while(a--)
                s += p.second;
        }
        return s;
    }
};