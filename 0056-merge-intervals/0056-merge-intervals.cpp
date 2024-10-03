class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(ans.empty() || s>ans.back()[1]){
                ans.push_back({s, e});
            }
            else{
                ans.back()[1]=max(ans.back()[1], e);
            }
        }
        return ans;
    }
};