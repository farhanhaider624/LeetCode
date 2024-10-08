class Solution {
public:
    // int fun(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp){
    //     if(ind==0){
    //         if(tar%coins[0]==0) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][tar]!=-1) return dp[ind][tar];
    //     int notTake = fun(ind-1, tar, coins, dp);
    //     int take = 0;
    //     if(coins[ind]<=tar) take = fun(ind, tar-coins[ind], coins, dp);
    //     return dp[ind][tar]=take + notTake;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0);
        for(int tar=0; tar<=amount; tar++){
            if(tar%coins[0]==0) prev[tar]=1;
        }
        for(int ind=1; ind<n; ind++){
            vector<int> curr(amount+1, 0);
            for(int tar=0; tar<=amount; tar++){
                int notTake = prev[tar];
                int take = 0;
                if(coins[ind]<=tar) take = curr[tar-coins[ind]];
                curr[tar]=take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};