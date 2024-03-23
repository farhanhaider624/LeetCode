class Solution {
private:
    // bool f(string p, string s, int i, int j, vector<vector<int>> &dp){
    //     //base case
    //     if(i==0 && j==0) return true;
    //     if(j>0 && i==0) return false;
    //     if(j==0 && i>0){
    //         for(int k=1; k<=i; k++) if(p[k-1]!='*') return false;
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     //dono equal or '?' ho to
    //     if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]=f(p, s, i-1, j-1, dp);
    //     //jb * ho
    //     else if(p[i-1]=='*') return dp[i][j]=(f(p, s, i, j-1, dp) || f(p, s, i-1, j, dp));
    //     else return dp[i][j]=false;
    // }
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0]=true;
        for(int j=1; j<=m; j++) dp[0][j]=false;
        for(int i=1; i<=n; i++){
            bool flag=true;
            for(int k=1; k<=i; k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //dono equal or '?' ho to
                if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                //jb * ho
                else if(p[i-1]=='*') dp[i][j]=dp[i][j-1] || dp[i-1][j];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};