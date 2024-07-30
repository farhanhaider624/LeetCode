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
    bool static comparator(vector<int> &v1, vector<int> &v2){
        return v1[2]<v2[2];
    }
    int Kruskals(vector<vector<int>> &vec){
        int sum = 0;
        for(auto &it:vec){
            int p1 = find(it[0]);
            int p2 = find(it[1]);
            int wt = it[2];
            if(p1!=p2){
                Union(it[0], it[1]);
                sum+=wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i]=i;
        vector<vector<int>> vec;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int wt = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vec.push_back({i, j, wt});
            }
        }
        sort(vec.begin(), vec.end(), comparator);
        return Kruskals(vec);
    }
};