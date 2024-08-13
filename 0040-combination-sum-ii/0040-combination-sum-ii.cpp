class Solution {
public:
    void func(int ind, int target, vector<int> &ds, vector<int> &candidates, vector<vector<int>> &ans){
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if(i!=ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            func(i+1, target-candidates[i], ds, candidates, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, target, ds, candidates, ans);
        return ans;
    }
};