class Solution {
private:
    int func(vector<int>&nums, int s, int e){
        int n=e-s+1;
        if(n==1) return nums[s];
        int prev2=nums[s];
        int prev=max(nums[s], nums[s+1]);
        for(int ind=s+2; ind<=e; ind++){
            int pick=nums[ind]+prev2;
            int notPick=prev;
            int curr= max(pick, notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]); 
        nums.push_back(nums[0]);
        return max(func(nums, 0, n-2), func(nums, 1, n-1));
    }
};