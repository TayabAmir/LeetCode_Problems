class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long> arr(edges.size(), 0);
        for(int i = 0; i < edges.size(); i++){
            arr[edges[i]] += i;
        }
        return distance(arr.begin(),max_element(arr.begin(), arr.end()));
    }
};