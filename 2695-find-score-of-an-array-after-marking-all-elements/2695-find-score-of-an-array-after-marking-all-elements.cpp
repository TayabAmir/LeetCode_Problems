class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < nums.size(); i++) pq.push({nums[i], i});

        vector<int> visited(nums.size(), false);

        long long score = 0;
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            if(!visited[p.second]){
                score += p.first;
                visited[p.second] = true;
                if(p.second-1 >= 0){
                    visited[p.second-1] = true;
                }
                if(p.second+1 < nums.size()){
                    visited[p.second+1] = true;
                }
            }
        }
        return score;
    }
};