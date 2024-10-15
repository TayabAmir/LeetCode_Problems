class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int ele : stones) pq.push(ele);
        
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            pq.push((x != y) ? x-y : 0);
        }
        
        return pq.top();
    }
};