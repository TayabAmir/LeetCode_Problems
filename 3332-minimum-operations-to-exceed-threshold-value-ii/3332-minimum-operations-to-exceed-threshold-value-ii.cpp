class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(int ele : nums)
            pq.push(ele);
        int ops = 0;
        while(pq.size() >= 2){
            long mini = pq.top(); pq.pop();
            if(mini >= k) return ops;
            long mini2 = pq.top(); pq.pop();
            pq.push(min(mini, mini2) * 2 + max(mini, mini2));
            ops++;
        }
        return ops;
    }
};