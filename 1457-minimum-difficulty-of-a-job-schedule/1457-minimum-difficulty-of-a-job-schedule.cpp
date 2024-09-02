class Solution {
public:
    // int func(int ind, int d, int n, vector<int>& jd, vector<vector<int>>& dp) {
    //     // base case
    //     if (d == 1) {
    //         return *max_element(begin(jd) + ind, end(jd));
    //     }
    //     if (dp[ind][d] != -1)
    //         return dp[ind][d];
    //     int maxD = jd[ind];
    //     int finalResult = INT_MAX;
    //     for (int i = ind; i <= n - d; i++) {
    //         maxD = max(maxD, jd[i]);
    //         int result = maxD + func(i + 1, d - 1, n, jd, dp);
    //         finalResult = min(finalResult, result);
    //     }
    //     return dp[ind][d] = finalResult;
    // }
    int minDifficulty(vector<int>& jd, int day) {
        int n = jd.size();
        if (n < day)
            return -1;
        vector<vector<int>> dp(301, vector<int>(11, 0));

        // base case
        for (int ind = 0; ind < n; ind++) {
            dp[ind][1] = *max_element(begin(jd) + ind, end(jd));
        }

        for (int d = 2; d<=day; d++) {
            for (int ind = 0; ind<=n-d; ind++) {
                int maxD = jd[ind];
                int finalResult = INT_MAX;
                for (int i = ind; i <= n - d; i++) {
                    maxD = max(maxD, jd[i]);
                    int result = maxD + dp[i + 1][d - 1];
                    finalResult = min(finalResult, result);
                }
                dp[ind][d] = finalResult;
            }
        }

        return dp[0][day];
    }
};