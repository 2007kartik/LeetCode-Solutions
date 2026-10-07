class Solution {
public:
    int dr[4] = {-1 , 0 , 1 , 0};
    int dc[4] = {0 , 1 , 0 , -1};
    bool isValid(int r , int c , int row , int col){
        return r>=0 && r<row && c>=0 && c<col;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //queue {{i , j} , steps}
        queue<pair<pair<int , int> ,int>>q;
        for(int i  = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i , j} , 0});
                }
            }
        }
        int steps  =0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            steps = q.front().second;
            q.pop();

            for(int k  = 0;k<4;k++){
                int drow = r + dr[k];
                int dcol = c + dc[k];
                if(isValid(drow , dcol , row , col)){
                    if(grid[drow][dcol]==1){
                        grid[drow][dcol] = 2;
                        q.push({{drow , dcol} , steps+1});
                    }
                }
            }
        }

        for(int i  = 0;i<row;i++){
            for(int j  = 0;j<col;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return steps;
        
    }
};