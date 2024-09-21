class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int, int> w;
        map<int, int> l;
        for(auto it:matches){
            w[it[0]]++;
            l[it[1]]++;
        }
        vector<int> temp;
        for(auto it:w){
            if(l.find(it.first)==l.end()) temp.push_back(it.first);
        }
        ans.push_back(temp);
        vector<int> temp2;
        for(auto it:l){
            if(it.second==1) temp2.push_back(it.first);
        }
        ans.push_back(temp2);
        return ans;
    }
};