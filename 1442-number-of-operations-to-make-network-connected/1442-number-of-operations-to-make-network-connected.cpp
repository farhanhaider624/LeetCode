class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<parent.size(); i++){
            parent[i]=i;
        }
        int edges = connections.size();
        if(edges<n-1) return -1;
        int components = n;
        for(auto &it:connections){
            int first_parent = find(it[0]);
            int second_parent = find(it[1]);
            if(first_parent==second_parent) continue;
            else{
                Union(it[0], it[1]);
                components--;
            }
        }
        return components-1;
    }
};