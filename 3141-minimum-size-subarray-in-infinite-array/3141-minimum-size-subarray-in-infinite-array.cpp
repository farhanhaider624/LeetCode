typedef long long ll;
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        unordered_map<int,int> suf,pre;
        int n = nums.size();
        ll ans = INT_MAX;
        ll sm=0;
        for(int i=0;i<n;i++)
        {
            sm+=nums[i]*1LL;
            if(sm==target)
                ans = min(ans,i+1LL);
            if(pre.find(sm-target)!=pre.end())
            {
               ans = min(ans,i*1LL-pre[sm-target]+1);
            }
            pre[sm] = i+1;
        }
        sm=0;
        for(int i=n-1;i>=0;i--)
        {
            sm+=nums[i]*1LL;
            suf[sm] = n-i;
        }
        ll p = target%sm;
        ll sd = target/sm;
        for(int i=0;i<n;i++)
        {
            if(suf.find(p)!=suf.end())
                ans = min(ans,sd*n+suf[p]+i);
            p-=nums[i];
        }
        p = target%sm;
        p+=sm;
        sd--;
        for(int i=0;i<n;i++)
        {
            if(suf.find(p)!=suf.end())
                ans = min(ans,sd*n+suf[p]+i);
            p-=nums[i];
        }
        return ans==INT_MAX ? -1 : ans;
    }
};