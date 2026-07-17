class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int mini = prices[0];
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            int profit = prices[i] - mini;
            ans = Math.max(ans , profit);
            if(prices[i] < mini){
                mini = prices[i];
            }
        }

        return ans ;
    }
}