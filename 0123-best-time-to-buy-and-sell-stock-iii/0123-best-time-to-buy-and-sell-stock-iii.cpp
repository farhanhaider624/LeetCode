class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size() || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1) return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1, 0, cap, prices, dp), 
                                                f(ind+1, 1, cap, prices, dp));
        return dp[ind][buy][cap]=max(prices[ind]+f(ind+1, 1, cap-1, prices, dp), 
                                     f(ind+1, 0, cap, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};