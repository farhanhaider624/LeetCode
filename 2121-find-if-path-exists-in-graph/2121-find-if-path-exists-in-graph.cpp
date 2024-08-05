class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n, 1e9);
        pq.push({0, source});
        dis[source]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dist = it.first;
            for(auto &adjNode:adj[node]){
                if(dist+1<dis[adjNode]){
                    dis[adjNode]=dist+1;
                    pq.push({dist+1, adjNode});
                }
            }
        }
        return (dis[destination]!=1e9);
    }
};