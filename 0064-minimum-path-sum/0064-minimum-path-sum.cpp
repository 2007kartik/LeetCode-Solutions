class Solution {
public:
    int solve(int m , int n  , vector<vector<int>>&grid , vector<vector<int>> &dp){
        if(m==0 && n==0){  

                return grid[m][n];

           }
           if(m<0) return INT_MAX;
           if(n<0) return INT_MAX;

           if(dp[m][n]!=-1) return dp[m][n];

            long long up = 0LL +grid[m][n] + solve(m-1 , n , grid , dp);
        
        
            long long left = 0LL+grid[m][n] +  solve(m , n-1 , grid , dp);
        
        int mini = min(up , left);
        return dp[m][n] = mini;
    }
    int minPathSum(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,-1));

        return solve(m-1,n-1 , grid , dp);
        
        
    }
};