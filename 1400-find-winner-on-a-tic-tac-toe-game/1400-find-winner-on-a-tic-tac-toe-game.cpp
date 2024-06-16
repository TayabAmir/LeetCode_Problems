class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> arr(3, vector<char>(3, ' '));
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            arr[row][col] = (i % 2 == 0) ? 'X' : 'O';
        }
        if(checkWinner(arr)=='X')
            return "A";
        if(checkWinner(arr)=='O')
            return "B";
        return moves.size()==9 ?  "Draw" : "Pending";
    }
    char checkWinner(vector<vector<char>>& arr){
        for(int i=0;i<3;i++){
            int xCount = 0,oCount=0;
            for(int j=0;j<3;j++){
                if(arr[i][j]=='X')
                    xCount++;
                else if(arr[i][j]=='O')
                    oCount++;
            }
            if(xCount==3) return 'X';
            else if(oCount==3) return 'O';
        }
        for(int i=0;i<3;i++){
            int xCount = 0,oCount=0;
            for(int j=0;j<3;j++){
                if(arr[j][i]=='X')
                    xCount++;
                else if(arr[j][i]=='O')
                    oCount++;
            }
            if(xCount==3) return 'X';
            else if(oCount==3) return 'O';
        }
        if((arr[0][0]=='X' && arr[1][1] == 'X' && arr[2][2] == 'X') || (arr[0][2]=='X' && arr[1][1] == 'X' && arr[2][0] == 'X'))
            return 'X';
        if((arr[0][0]=='O' && arr[1][1] == 'O' && arr[2][2] == 'O') || (arr[0][2]=='O' && arr[1][1] == 'O' && arr[2][0] == 'O'))
            return 'O';
        return ' ';
    }
};