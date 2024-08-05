class Solution {
public:
    bool bfsCheckBipartite(vector<int> adj[], int node, vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &adjNode: adj[node]){
                if(color[adjNode]==-1){
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                }
                else{
                    if(color[adjNode]==color[node]) return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto &it: dislikes){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(bfsCheckBipartite(adj, i, color)==false) return false;
            }
        }
        return true;
    }
};