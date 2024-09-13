class Solution {
public:
    void bfs(int i, vector<int> &dist, vector<int> adj[]){
        queue<pair<int, int>> q;
        dist[i]=0;
        q.push({0, i});
        while(!q.empty()){
            auto itr=q.front();
            int dis=itr.first;
            int node=itr.second;
            q.pop();
            for(auto it:adj[node]){
                if(1+dis<dist[it]){
                    dist[it]=min(dist[it], 1+dis);
                    q.push({dist[it], it});
                }else if(dist[it]==-1){
                    dist[it]=1+dis;
                    q.push({dist[it], it});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            int u=i;
            int v=edges[i];
            if(v!=-1) adj[u].push_back(v);
        }
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        bfs(node1, dist1, adj);
        bfs(node2, dist2, adj);
        int node=-1;
        int value=n;
        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(max(dist1[i], dist2[i])<value){
                    value=max(dist1[i], dist2[i]);
                    node=i;
                }
            }
        }
        return node;
    }
};