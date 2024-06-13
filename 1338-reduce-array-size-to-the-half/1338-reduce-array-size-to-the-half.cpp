class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int halfSize=floor(n/2);
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        for(int i=0; i<n; i++) mp[arr[i]]++;
        for(auto &it:mp) pq.push(it.second);
        int totalSize=pq.size();
        while(!pq.empty() && halfSize>0){
            halfSize-=pq.top();
            pq.pop();
        }
        return totalSize-pq.size();
    }
};