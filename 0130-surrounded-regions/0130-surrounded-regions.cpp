class Solution {
public:

    int dr[4] = {-1 , 0 , 1 , 0};
    int dc[4] ={ 0 , 1 , 0 , -1};
    bool isValid(int r , int c , int row , int col ){
        return r>=0 && r<row && c>=0 && c<col;
    }

    void dfs(int i , int j , vector<vector<int>> &vis  , vector<vector<char>>& board , int row , int col){
        vis[i][j] =1;
        for(int k  = 0;k<4;k++){
            int drow = i + dr[k];
            int dcol = j + dc[k];
            if(isValid(drow , dcol ,row , col )){
            if(!vis[drow][dcol] && board[i][j]=='O'){
                dfs(drow , dcol , vis , board , row , col);
            }
            }
            
        }
    }

    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col  = board[0].size();
        vector<vector<int>> vis(row , vector<int>(col , 0));

        for(int j  = 0;j<col;j++){
           if(!vis[0][j] && board[0][j]=='O') dfs(0 , j , vis , board , row , col);
           if(!vis[row-1][j] && board[row-1][j]=='O') dfs(row-1 , j , vis , board , row , col);
        }
        
        for(int i  =0;i<row;i++){
           if(!vis[i][0] && board[i][0]=='O') dfs(i , 0 , vis , board , row , col);
           if(!vis[i][col-1] && board[i][col-1]=='O') dfs(i , col-1 , vis , board , row , col);
        }
        for(int i  = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};