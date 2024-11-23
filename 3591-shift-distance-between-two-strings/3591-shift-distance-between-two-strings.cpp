class Solution {
public:
    long long calculateDistance(char s,char t,vector<int>& nextCost,vector<int>& previousCost){
        long long n = 0, p = 0;
        for (int i = s-'a'; i != t-'a'; i = (i + 1) % 26) n += nextCost[i];
        for (int i = s-'a'; i != t-'a'; i = (i - 1 + 26) % 26) p += previousCost[i];
        return min(n, p);
    }
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[i]){
                res += calculateDistance(s[i], t[i],nextCost, previousCost);
            }
        }
        return res;
    }
};