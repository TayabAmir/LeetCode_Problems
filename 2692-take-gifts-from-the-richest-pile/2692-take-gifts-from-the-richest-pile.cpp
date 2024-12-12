class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int ele : gifts) pq.push(ele);

        while(k--){
            int ele = pq.top(); pq.pop();
            pq.push(floor(sqrt(ele)));
        }
        long long totalGifts = 0;
        while(!pq.empty()){
            totalGifts += pq.top(), pq.pop();
        }
        return totalGifts;
    }
};