class Solution {
private:
    int func(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j]= func(s, t, i-1, j-1, dp);
        return dp[i][j]=1+min(func(s, t, i, j-1, dp) ,min(func(s, t, i-1, j, dp),func(s, t, i-1, j-1, dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n==0 || m==0){
            if(m!=0) return m;
            if(n!=0) return n;
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(word1, word2, n-1, m-1, dp);
    }
};