class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto &it: mp){
            // cout<<it.first<<" "<<it.second<<endl;
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};