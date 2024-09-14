class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxEle=*max_element(nums.begin(), nums.end());
        int maxLen=0, len=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maxEle) len++;
            else len=0;
            maxLen=max(maxLen, len);
        }
        return maxLen;
    }
};