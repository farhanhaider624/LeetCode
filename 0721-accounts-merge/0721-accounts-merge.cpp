class Solution {
    public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp==yp) return;
        if(rank[xp]>rank[yp]) parent[yp]=xp;
        if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[yp]=xp;
            rank[xp]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;
        unordered_map<string, int> mapMailNode;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                } else{
                    Union(i, mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto &it:mapMailNode){
            string mail = it.first;
            int node = find(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;

        for(int i=0; i<n; i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};