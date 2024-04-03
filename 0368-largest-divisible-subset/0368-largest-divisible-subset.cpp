class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1), trace(n, 0);
        for(int i=0; i<n; i++) trace[i]=i;
        int maxi=1;
        int lastIndex=0;
        sort(nums.begin(), nums.end());
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[ind]%nums[prev]==0 && dp[ind]<dp[prev]+1){
                    dp[ind]=dp[prev]+1;
                    trace[ind]=prev;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(lastIndex!=trace[lastIndex]){
            lastIndex=trace[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        return ans;
        
    }
};