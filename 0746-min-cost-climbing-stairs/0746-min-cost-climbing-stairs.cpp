class Solution {
private:
    int f(vector<int> &cost, int ind, vector<int> &dp){
        //base case
        if(ind>=cost.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //single step
        int single_step=cost[ind]+f(cost, ind+1, dp);
        //double step
        int double_step=cost[ind]+f(cost, ind+2, dp);
        return dp[ind]=min(single_step, double_step);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n, -1);
        return min(f(cost, 0, dp), f(cost, 1, dp));
    }
};