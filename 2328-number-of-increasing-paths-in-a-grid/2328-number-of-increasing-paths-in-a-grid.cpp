class Solution {
public:
    int drow[4]=  {-1   , 0 , 1 , 0};
    int dcol[4] = {0 , 1 , 0 , -1};
    const int mod = 1000000007;
   
    int solve(int i , int j  , int row , int col , vector<vector<int>>& matrix, vector<vector<int>> &dp){
        
        int ans = 1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k = 0;k<4;k++){
            int nr = i + drow[k];
            int nc = j+ dcol[k];

            if(nr>=0 && nc>=0 && nr<row && nc<col){
                if(matrix[nr][nc]>matrix[i][j]){
                    ans  = (ans + solve(nr , nc , row , col , matrix,dp))%mod;
                }
            }
        }
        return dp[i][j] = ans;

      
    }
    int countPaths(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(row , vector<int>(col , -1));

        for(int i  = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                ans = (ans +solve(i , j , row , col , grid , dp))%mod;
            }
        }
        
        return ans;
    }
};