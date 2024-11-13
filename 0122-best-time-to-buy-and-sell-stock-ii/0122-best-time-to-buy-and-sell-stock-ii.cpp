class Solution {
public:
    // int func(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     if(ind==prices.size()){
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit=0;
    //     if(buy){
    //         //take or not take
    //         profit=max(-prices[ind]+func(ind+1, 0, prices, dp), func(ind+1, 1, prices, dp));
    //     }
    //     else{
    //         profit=max(prices[ind]+func(ind+1, 1, prices, dp), func(ind+1, 0, prices, dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int ind=0, buy=1;
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy){
                    //take or not take
                    profit=max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+dp[ind+1][1], dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};