class Solution {
private:
    // int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     //base case
    //     if(ind==prices.size()) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[ind]+f(ind+1, 0, prices, dp), 0+f(ind+1, 1, prices, dp));
    //     }
    //     else profit=max(prices[ind]+f(ind+1, 1, prices, dp), 0+f(ind+1, 0, prices, dp));
    //     return dp[ind][buy]=profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        ahead[0]=ahead[1]=0;

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+ahead[0], 0+ahead[1]);
                }
                else profit=max(prices[ind]+ahead[1], 0+ahead[0]);
                curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[1];
    }
};