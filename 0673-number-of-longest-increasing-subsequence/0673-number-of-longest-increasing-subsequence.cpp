class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
	    int maxi=1;
		for(int i=0; i<n; i++){
			for(int prev=0; prev<i; prev++){
				if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                    cnt[i]=cnt[prev];
                }
                 else if(arr[i]>arr[prev] && 1+dp[prev]==dp[i]){
                     cnt[i]+=cnt[prev];
                 }
			}
            maxi=max(maxi, dp[i]);
	    }
        int totalCnt=0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxi) totalCnt+=cnt[i];
        }
        return totalCnt;
    }
};