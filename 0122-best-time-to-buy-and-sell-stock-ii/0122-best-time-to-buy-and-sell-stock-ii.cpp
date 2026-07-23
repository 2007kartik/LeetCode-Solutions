class Solution {
public:
    int solve(int ind ,int buy , int n , vector<int>&p , vector<vector<int>>&dp){

        if(ind==n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy){

            return dp[ind][buy] = max( -p[ind]+solve(ind+1 , 0 ,n , p ,dp) , 0+solve(ind+1 , 1 , n , p ,dp));


        }
        else{
                return dp[ind][buy] = max(p[ind]+solve(ind+1 , 1 ,n , p ,dp) , 0+solve(ind+1 , 0 , n , p ,dp));
        }



    }
    int maxProfit(vector<int>& prices) {

       int sz = prices.size();
       vector<vector<int>> dp(sz , vector<int>(2 , -1));
      return  solve(0 ,1 , sz , prices , dp);
        
    }
};