class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool solve(int ind, string &s){
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        if(st.find(s)!=st.end()) return true;
        for(int l=1; l<=s.size(); l++){
            string temp=s.substr(ind, l);
            if(st.find(temp)!=st.end() && solve(ind+l, s)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        for(auto it:wordDict) st.insert(it);
        return solve(0, s);
    }
};