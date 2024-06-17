class Solution {
public:
    typedef pair<int, pair<int,int>> ppi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        set<pair<int, int>> s;
        vector<vector<int>> ans;
        pq.push({nums1[0]+nums2[0], {0, 0}});
        s.insert({0, 0});
        
        for(int i=0; i<k; i++){
            pair<int, int> p = pq.top().second;
            pq.pop();
            ans.push_back({nums1[p.first], nums2[p.second]});
            
            if(p.first+1<nums1.size() && s.find({p.first+1, p.second})==s.end()){
                pq.push({nums1[p.first+1]+nums2[p.second], {p.first+1, p.second}});
                s.insert({p.first+1, p.second});
            }
            if(p.second+1<nums2.size() && s.find({p.first, p.second+1})==s.end()){
                pq.push({nums1[p.first]+nums2[p.second+1], {p.first, p.second+1}});
                s.insert({p.first, p.second+1});
            }
        }
        return ans;
    }
};