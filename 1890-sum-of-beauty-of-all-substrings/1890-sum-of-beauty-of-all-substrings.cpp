class Solution {
public:
    int beautySum(string s) {
        int score = 0;
        for (int i = 0; i < s.length(); i++) 
        {    
            vector<int> vMax(26,INT_MIN);
            vector<int> vMin(26,INT_MAX);
            for (int j = i; j < s.length(); j++) 
            {
                (vMax[s[j]-'a']==INT_MIN) ? vMax[s[j]-'a'] = 1 : vMax[s[j]-'a']++;
                (vMin[s[j]-'a']==INT_MAX) ? vMin[s[j]-'a'] = 1 : vMin[s[j]-'a']++;
                int a = *max_element(vMax.begin(),vMax.end());
                int b = *min_element(vMin.begin(),vMin.end());
                score += (a-b);
            }
        }
        return score;
    }
};