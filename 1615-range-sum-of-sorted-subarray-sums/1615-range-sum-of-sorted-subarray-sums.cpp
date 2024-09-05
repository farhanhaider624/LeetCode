class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                arr.push_back(sum%mod);
            }
        }
        sort(arr.begin(), arr.end());
        // int l=left-1, r=right-1;
        int sum=0;
        for(int i=left-1; i<=right-1; i++){
            sum+=arr[i];
            sum=sum%mod;
        }
        return sum%mod;
    }
};