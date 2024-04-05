class Solution {
public:
    // int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee){
    //     //base case
    //     if(ind==prices.size()) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy==1) return dp[ind][buy]=max(-fee-prices[ind]+f(ind+1, 0, prices, dp, fee),
    //                          f(ind+1, 1, prices, dp, fee));
    //     return dp[ind][buy]=max(prices[ind]+f(ind+1, 1, prices, dp, fee), f(ind+1, 0, prices, dp, fee));
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> after(2, 0);
        vector<int> cur(2, 0);
        
        for(int ind=n-1; ind>=0; ind--){
            cur[1]=max(-fee-prices[ind]+after[0],
                             after[1]);
            cur[0]=max(prices[ind]+after[1], after[0]);
            after=cur;
        }
        
        return after[1];
    }
};