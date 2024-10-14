class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int ele : nums) 
            pq.push(ele);
        long long score = 0;
        while(k--){
            int ele = pq.top();pq.pop();
            cout << ele;
            score += ele;
            pq.push(ceil(ele/3.0));
        }
        return score;

    }
};