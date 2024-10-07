class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < arr.size(); i++){
            minHeap.push({arr[i], i});
        }
        int rank = 0, ele = INT_MIN;
        while(!minHeap.empty()){
            if(minHeap.top().first != ele) rank++;
            arr[minHeap.top().second] = rank;
            ele = minHeap.top().first;
            minHeap.pop();
        }
        return arr;
    }
};