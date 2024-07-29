class Solution {
public:
    #define ll long long
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
        else if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;
        for(auto &it:edges){
            Union(it[0], it[1]);
        }
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[find(i)]++;
        }
        ll totalPairs=0;
        ll sumSizes = 0;
        for(auto &it:mp){
            int size = it.second;
            totalPairs+=sumSizes*size;
            sumSizes+=size;
        }
        return totalPairs;
    }
};