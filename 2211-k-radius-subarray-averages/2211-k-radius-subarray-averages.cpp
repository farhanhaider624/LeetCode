class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return nums;
        vector<int> ans(n, -1);
        if(n<2*k+1) return ans;
        vector<long long> prefixSum(n, 0);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=k; i<n-k; i++){
            if(i-k>=0 && i+k<n){
                long long sum=prefixSum[i+k];
                if(i-k>0) sum-=prefixSum[i-k-1];
                ans[i]=sum/(2*k+1);
            }
        }
        return ans;
    }
};