class Solution {
public:
    // int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     //base case
    //     if(ind>=prices.size()) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy==1) return dp[ind][buy]=max(-prices[ind]+f(ind+1, 0, prices, dp),
    //                          f(ind+1, 1, prices, dp));
    //     return dp[ind][buy]=max(prices[ind]+f(ind+2, 1, prices, dp), f(ind+1, 0, prices, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> cur(2, 0);
        
        for(int ind=n-1; ind>=0; ind--){
                cur[1]=max(-prices[ind]+front1[0],
                             front1[1]);
                cur[0]=max(prices[ind]+front2[1], front1[0]);
            front2=front1;
            front1=cur;
        }
        
        return front1[1];
    }
};