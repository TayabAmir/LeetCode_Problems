class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(int i : arr) m[i]++;

        priority_queue<int> pq;
        for(auto p : m) pq.push(p.second);
        
        int sum = 0, size = pq.size();
        while(!pq.empty()){
            if(sum < arr.size()/2) 
                sum += pq.top();
            else 
                break;
            pq.pop();
        }
        return size - pq.size();
    }
};