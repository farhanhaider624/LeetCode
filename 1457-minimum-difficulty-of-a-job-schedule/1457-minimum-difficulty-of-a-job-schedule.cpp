class Solution {
public:
    int func(int ind, int d, int n, vector<int> &jd, vector<vector<int>> &dp){
        //base case
        if(d==1){
            return *max_element(begin(jd)+ind, end(jd));
        }
        if(dp[ind][d]!=-1) return dp[ind][d];
        int maxD=jd[ind];
        int finalResult = INT_MAX;
        for(int i=ind; i<=n-d; i++){
            maxD = max(maxD, jd[i]);
            int result = maxD + func(i+1, d-1, n, jd, dp);
            finalResult = min(finalResult, result);
        }
        return dp[ind][d]=finalResult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d) return -1;
        vector<vector<int>> dp(301, vector<int>(11, -1));
        return func(0, d, n, jd, dp);
    }
};