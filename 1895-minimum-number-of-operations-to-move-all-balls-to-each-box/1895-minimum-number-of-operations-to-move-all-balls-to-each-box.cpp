class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> bI;
        for(int i = 0; i < boxes.size(); i++)
            if(boxes[i] == '1')
                bI.push_back(i);
        vector<int> res(boxes.size());
        for(int i = 0; i < boxes.size(); i++){
            int moves = 0;
            for(int idx : bI)
                moves += abs(idx-i);
            res[i] = moves;
        }
        return res;
    }
};