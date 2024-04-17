class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid = {{0,0,0}, {0,0,0}, {0,0,0}};
        int turn=1;
        for(vector<int> move : moves) {
            if(turn==1 && grid[move[0]][move[1]]==0) {
                grid[move[0]][move[1]]=1;
            } else if(turn==-1 && grid[move[0]][move[1]]==0) {
                grid[move[0]][move[1]]=-1;
            }
            turn*=-1;
        }

        int row_sum, col_sum;
        for(int i=0;i<3;i++) {
            row_sum=0;
            col_sum=0;
            for(int j=0;j<3;j++) {
                row_sum+=grid[i][j];
                col_sum+=grid[j][i];
            }

            if(row_sum==3 || col_sum==3) return "A";

            if(row_sum==-3 || col_sum==-3) return "B";
        }

        //to check diagonals
        if(grid[0][0]+grid[1][1]+grid[2][2]==3 || grid[0][2]+grid[1][1]+grid[2][0]==3) return "A";
        if(grid[0][0]+grid[1][1]+grid[2][2]==-3 || grid[0][2]+grid[1][1]+grid[2][0]==-3) return "B";

        if(moves.size()<9) return "Pending";

        return "Draw";
    }
};