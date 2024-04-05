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
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> cur(2, vector<int>(k+1, 0));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int kk=1; kk<=k; kk++){
                    if(buy==1) cur[buy][kk]=max(-prices[ind]+after[0][kk],
                             after[1][kk]);
                    else cur[buy][kk]=max(prices[ind]+after[1][kk-1],
                                        after[0][kk]);
                }
            }
            after=cur;
        }
        return after[1][k];
    }
};