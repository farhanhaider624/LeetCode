class Solution {
// private:
    // int func(int i, int j, string s, string t, vector<vector<int>> &dp){
    //     if(j==0) return 1;
    //     if(i==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i-1]==t[j-1]){
    //         return dp[i][j]=func(i-1,j-1,s,t, dp)+func(i-1, j,s,t, dp);
    //     }
    //     return dp[i][j]=func(i-1, j,s,t, dp);
    // }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1, 0), curr(m+1, 0);
        
        for(int i=0; i<=n; i++) {
            curr[0]=1;
            prev[0]=1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1]+prev[j];
                }
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)prev[m];
    }
};