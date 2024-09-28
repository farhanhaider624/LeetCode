class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int i=0, j;
        for(; i<n; i++){
            if(nums[i]==0){
                j=i+1;
                break;
            }
        }
        for(; j<n; j++){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};