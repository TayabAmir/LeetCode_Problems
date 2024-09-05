class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(int ele : rolls)
            sum += ele;
        int remaining = (mean * (rolls.size() + n)) - sum;

        vector<int> ans;
        while(n){
            sum = remaining / n--;
            if(sum <= 0 || sum > 6) return {};
            ans.push_back(sum), remaining -= sum;
        }
        return ans;
    }
};