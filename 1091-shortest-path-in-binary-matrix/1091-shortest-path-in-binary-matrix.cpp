class Solution {
public:
    int drow[8]  = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
    int dcol[8] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        if(row==1 && col==1 && grid[0][0] == 0)return 1;
        vector<vector<int>> dis(row , vector<int>(col ,1e9));


        if(grid[0][0] == 1)return -1;
        queue<pair<pair<int , int> , int>> q;
        q.push({{0 , 0} ,1});

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();

            for(int i  = 0;i<8;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<row&&ncol<col&&grid[nrow][ncol]==0){
                    grid[nrow][ncol] = 1;
                    if(step+1<dis[nrow][ncol]){
                        dis[nrow][ncol] = step+1;
                        q.push({{nrow , ncol} ,step+1});
                    }

                }
            }
        }

        if(dis[row-1][col-1]==1e9) return -1;
        return dis[row-1][col-1];
    }
};