class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0, j=0;
        int maxScore=0;
        int score=0;
        unordered_map<int, int> mp;
        while(j<nums.size()){
            score+=nums[j];
            mp[nums[j]]++;
            while(!mp.empty() && j-i+1!=mp.size()){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                score-=nums[i];
                i++;
            }
            maxScore=max(maxScore, score);
            j++;
        }
        return maxScore;
    }
};