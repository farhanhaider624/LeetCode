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

    int removeStones(vector<vector<int>>& stones) {
        int noOfStones = stones.size();
        int maxRow = 0;
        int maxCol=0;
        for(auto &it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int n = maxRow + maxCol + 2;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;
        unordered_map<int, int> stoneNodes;
        for(auto &it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            Union(nodeRow, nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        // now we will find the number of ultimate parents or total parents;
        int cnt=0;
        for(auto &it:stoneNodes){
            if(find(it.first)==it.first) cnt++;
        }
        return noOfStones-cnt;
    }
};