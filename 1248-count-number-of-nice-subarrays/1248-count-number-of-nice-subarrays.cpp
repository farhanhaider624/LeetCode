class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        map<int, int> mp;
        mp[0]=1;
        long long sum=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};