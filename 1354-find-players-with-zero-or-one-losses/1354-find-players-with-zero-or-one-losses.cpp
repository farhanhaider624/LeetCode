class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> w, l;
        for(auto it:matches){
            w[it[0]]++;
            l[it[1]]++;
        }
        for(auto it:w){
            if(l.find(it.first)==l.end()) ans[0].push_back(it.first);
        }
        for(auto it:l){
            if(it.second==1) ans[1].push_back(it.first);
        }
        return ans;
    }
};