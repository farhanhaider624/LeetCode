class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int deg=0;
        for(auto &it:nums){
            mp[it]++;
            deg=max(deg, mp[it]);
            // cout<<mp[it]<<endl;
        }
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]--;
        }
        
        int i=0, j=0;
        int maxi=0;
        int len=1e5;
        while(j<nums.size()){
            mp[nums[j]]++;
            maxi=max(mp[nums[j]], maxi);
            // cout<<mp[nums[j]]<<" "<<maxi<<endl;
            cout<<maxi<<" ";
            while(maxi==deg){
                // cout<<"Hi";
                len=min(len, j-i+1);
                if(mp[nums[i]]==maxi) maxi--;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return len;
    }
};