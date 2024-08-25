class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mp.find(mod)!=mp.end()){
                if(i-mp[mod]>=2) return true;
            }
            else mp[mod]=i;
        }
        return false;
    }
};