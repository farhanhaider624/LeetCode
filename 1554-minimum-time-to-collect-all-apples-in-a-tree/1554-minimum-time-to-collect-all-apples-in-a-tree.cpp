class Solution {
public:
    int dfs(vector<int> adj[], int node, int parent, vector<bool> &hasApple){
        int time=0;
        for(auto &child:adj[node]){
            if(child==parent) continue;
            int time_from_child = dfs(adj, child, node, hasApple);
            if(time_from_child>0 || hasApple[child]){
                time+=time_from_child+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};