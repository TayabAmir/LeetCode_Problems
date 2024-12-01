class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int ele : arr) m[ele]++;

        for(int ele : arr){
            if(ele != 0){
                if(m.find(ele*2) != m.end()) return true;
            } else {
                if(m[0] >= 2) return true;
            }
        }
        return false;
    }
};