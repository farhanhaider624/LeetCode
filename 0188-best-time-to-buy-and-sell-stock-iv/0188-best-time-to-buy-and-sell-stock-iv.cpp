class Solution {
public:
    // int f(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
    //     if(ind==prices.size() || k==0) return 0;
    //     if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
    //     if(buy==1) return dp[ind][buy][k]=max(-prices[ind]+f(ind+1, 0, k, prices, dp),
    //                          f(ind+1, 1, k, prices, dp));
    //     return dp[ind][buy][k]=max(prices[ind]+f(ind+1, 1, k-1, prices, dp),
    //                         f(ind+1, 0, k, prices, dp));
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int kk=1; kk<=k; kk++){
                    if(buy==1) dp[ind][buy][kk]=max(-prices[ind]+dp[ind+1][0][kk],
                             dp[ind+1][1][kk]);
                    else dp[ind][buy][kk]=max(prices[ind]+dp[ind+1][1][kk-1],
                                        dp[ind+1][0][kk]);
                }
            }
        }
        return dp[0][1][k];
    }
};