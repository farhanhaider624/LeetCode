class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<int> adj[]){
        vis[i]=1;
        for(auto &it: adj[i]){
            if(!vis[it]) dfs(it, vis, adj);        
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], indegree(n, 0);
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans, vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(indegree[i]==0) ans.push_back(i);
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};