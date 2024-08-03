class DisjointSet{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++) parent[i]=i;
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void UnionByRank(int x, int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp) return;
        if(rank[xp]>rank[yp]) parent[yp]=xp;
        else if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    void UnionBySize(int x, int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp) return;
        if(size[xp]<size[yp]){
            parent[xp]=yp;
            size[yp]+=size[xp];
        }
        else{
            parent[yp]=xp;
            size[xp]+=size[yp];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delRow[]={-1, 0, 1, 0};
        int delCol[]={0, -1, 0, 1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int k=0; k<4; k++){
                    int nr = i + delRow[k];
                    int nc = j + delCol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int cell = (i*n)+j;
                        int adjCell = (nr*n)+nc;
                        ds.UnionBySize(cell, adjCell);
                    }
                }
            }
        }
        int maxSize=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                unordered_set<int> components;
                for(int k=0; k<4; k++){
                    int nr = i + delRow[k];
                    int nc = j + delCol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adjCell = (nr*n)+nc;
                        components.insert(ds.find(adjCell));
                    }
                }
                int totalSize = 0;
                for(auto &it:components){
                    totalSize+=ds.size[it];
                }
                maxSize=max(maxSize, totalSize+1);
            }
        }
        for(int cell=0; cell<n*n; cell++){
            maxSize = max(maxSize, ds.size[ds.find(cell)]);
        }
        return maxSize;
    }
};