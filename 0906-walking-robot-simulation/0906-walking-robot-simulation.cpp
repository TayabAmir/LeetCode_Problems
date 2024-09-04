class Solution {
public:
    int calculateDistance(int x, int y){
        return x*x + y*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int direction = 1, euclideanDistance = INT_MIN;
        set<pair<int,int>> s;
        for(auto v : obstacles)
            s.insert({v[0],v[1]});
        for(int i = 0; i < commands.size(); ++i){
            if(commands[i] == -1){
                direction = (direction % 4) + 1;
            } else if(commands[i] == -2){
                direction = direction - 1;
                if(direction == 0) direction = 4;
            } else {
                if(direction == 1){
                    for(int j = 0; j < commands[i]; j++){
                        if(s.find({x, y+1}) != s.end()) break;
                        y++;
                    }
                } else if(direction == 2){
                    for(int j = 0; j < commands[i]; j++){
                        if(s.find({x+1, y}) != s.end()) break;
                        x++;
                    }
                } else if(direction == 3){
                    for(int j = 0; j < commands[i]; j++){
                        if(s.find({x, y-1}) != s.end()) break;
                        y--;
                    }
                } else {
                    for(int j = 0; j < commands[i]; j++){
                        if(s.find({x-1, y}) != s.end()) break;
                        x--;
                    }
                }
            }
            euclideanDistance = max(euclideanDistance, calculateDistance(x,y));
        }
        return euclideanDistance;
    }
};