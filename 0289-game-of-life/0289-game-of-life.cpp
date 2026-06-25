class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> temp(rows , vector<int>(cols , 0));

        int dx[] = {-1,-1,-1,0,0,1,1,1};//wrt row pointer
        int dy[] = {-1,0,1,-1,1,-1,0,1};//wrt col pointer

        for(int i = 0;i<rows;i++){
            for(int j  = 0;j<cols;j++){
                int count = 0;
                for(int k = 0;k<8;k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];
                    if(nr>=0&&nc>=0&&nr<rows&&nc<cols){
                            if(board[nr][nc]==1){
                                count++;
                            }
                    }
                
                }
                if(board[i][j]==1){

                        if(count<2){
                            temp[i][j] = 0;
                        }
                        else if(count==2||count==3){
                            temp[i][j] = 1;
                        }
                        else temp[i][j] = 0;

                }
                else{
                    if(count==3){
                        temp[i][j] = 1;

                    }
                    else temp[i][j]  = 0;
                }
            }
        }
        board = temp;
          
    }
};