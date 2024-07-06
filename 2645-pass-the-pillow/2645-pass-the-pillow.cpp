class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1,direction = 1;
        while(time--){
            if(direction==1)
                i++;
            else
                i--;
            if(i==n) direction=-1;
            else if(i==1) direction=1;
        }
        return i;
    }
};