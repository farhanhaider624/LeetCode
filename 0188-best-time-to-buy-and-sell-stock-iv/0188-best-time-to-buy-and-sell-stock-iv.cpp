class Solution {
public:
    int f(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size() || k==0) return 0;
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        if(buy==1) return dp[ind][buy][k]=max(-prices[ind]+f(ind+1, 0, k, prices, dp),
                             f(ind+1, 1, k, prices, dp));
        return dp[ind][buy][k]=max(prices[ind]+f(ind+1, 1, k-1, prices, dp),
                            f(ind+1, 0, k, prices, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices, dp);
    }
};