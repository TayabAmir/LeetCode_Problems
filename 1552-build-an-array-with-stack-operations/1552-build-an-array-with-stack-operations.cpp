class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s;
        for(int i = 1; i <= n && target.size()>0; i++){
            auto itr = find(target.begin(),target.end(),i);
            if(itr != target.end()) {
                target.erase(itr);
                s.push_back("Push");
            } else {
                s.push_back("Push");
                s.push_back("Pop");
            }
        }
        return s;
    }
};