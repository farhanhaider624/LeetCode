class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        int ans=1;
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[ind]>nums[prev]) dp[ind]=max(1+dp[prev], dp[ind]);
                ans=max(ans, dp[ind]);
            }
        }
        return ans;
    }
};