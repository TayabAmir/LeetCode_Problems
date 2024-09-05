class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(int ele : rolls)
            sum += ele;
        int remaining = (mean * (rolls.size() + n)) - sum;
        if(remaining > n * 6 || remaining <= 0) return {};

        vector<int> ans;
        while(n){
            int dice = remaining / n;
            if(dice <= 0) return {};
            ans.push_back(dice);
            remaining -= dice, n--;
        }
        return ans;
    }
};