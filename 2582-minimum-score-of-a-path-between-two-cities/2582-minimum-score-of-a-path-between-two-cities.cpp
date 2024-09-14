class Solution {
public:
    int minDis=INT_MAX;
    void dfs(int i, vector<vector<int>> adj[], vector<int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            int adjNode=it[0];
            int dis=it[1];
            if(!vis[adjNode]){
                vis[adjNode]=1;
                dfs(adjNode, adj, vis);
            }
            minDis=min(minDis, dis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n + 1];
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int dis = it[2];
            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }
        queue<int> q;
        vector<int> vis(n+1, 0);
        dfs(1, adj, vis);
        return minDis;
    }
};