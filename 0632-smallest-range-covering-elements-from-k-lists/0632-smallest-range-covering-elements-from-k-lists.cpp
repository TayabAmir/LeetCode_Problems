class Node {
public:
    int i;
    int j;
    int data;
    Node(int i, int j, int data){
        this->i = i;
        this->j = j;
        this->data = data;
    }
};
class comp {
public:
    bool operator()(Node a, Node b){
        return a.data > b.data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN;
        priority_queue<Node, vector<Node>, comp> pq; 
        for(int i = 0; i < nums.size(); ++i){
            pq.push(Node(i, 0, nums[i][0]));
            maxi = max(maxi, nums[i][0]);
        }
        int rangeMini = pq.top().data, rangeMaxi = maxi;
        while(!pq.empty()){
            Node top = pq.top();
            pq.pop();
            int i = top.i, j = top.j, data = top.data;
            if(rangeMaxi - rangeMini > maxi - data){
                rangeMini = data, rangeMaxi = maxi;
            }
            if(j + 1 < nums[i].size()){
                pq.push(Node(i, j+1, nums[i][j+1]));
                maxi = max(maxi, nums[i][j+1]);
            } else {
                break;
            }
        }
        return {rangeMini, rangeMaxi};
    }
};