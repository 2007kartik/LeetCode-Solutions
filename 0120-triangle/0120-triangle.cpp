class Solution {
public:
    int solve(int i , int j , int sz , vector<vector<int>>& triangle , vector<vector<int>> &dp){

            if(i==sz-1){
                return triangle[i][j];
            }

            if(dp[i][j]!=INT_MAX) return dp[i][j];
            int down = triangle[i][j] + solve(i+1 ,j , sz , triangle ,dp);
            int downDigonal = triangle[i][j] + solve(i+1 , j+1 , sz , triangle  ,dp);
            return dp[i][j] = min(down , downDigonal);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<vector<int>> dp(sz , vector<int>(sz , INT_MAX));

        return solve(0,0 ,sz , triangle ,dp );
        
    }
};