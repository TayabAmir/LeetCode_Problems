class Solution {
public:
    int calculateDistance(int x, int y){
        return x*x + y*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int direction = 1, euclideanDistance = INT_MIN;
        map<pair<int,int>,int> m;
        for(auto v : obstacles)
            m[{v[0],v[1]}] = 1;
        for(int i = 0; i < commands.size(); ++i){
            if(commands[i] == -1){
                direction = (direction % 4) + 1;
            } else if(commands[i] == -2){
                direction = direction - 1;
                if(direction == 0) direction = 4;
            } else {
                int points = commands[i];
                if(direction == 1){
                    for(int i = 0; i < points; i++){
                        if(m[{x, y+1}] == 1) break;
                        y++;
                    }
                } else if(direction == 2){
                    for(int i = 0; i < points; i++){
                        if(m[{x+1, y}] == 1) break;
                        x++;
                    }
                } else if(direction == 3){
                    for(int i = 0; i < points; i++){
                        if(m[{x, y-1}] == 1) break;
                        y--;
                    }
                } else {
                    for(int i = 0; i < points; i++){
                        if(m[{x-1, y}] == 1) break;
                        x--;
                    }
                }
            }
            euclideanDistance = max(euclideanDistance, calculateDistance(x,y));
        }
        return euclideanDistance;
    }
};