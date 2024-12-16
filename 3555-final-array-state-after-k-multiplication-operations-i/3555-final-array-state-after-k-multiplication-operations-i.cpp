class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }
        while(k--){
            auto p = pq.top(); pq.pop();
            nums[p.second] *= m;
            pq.push({nums[p.second],p.second});
        }
        return nums;
    }
};