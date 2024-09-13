class Solution {
public:
    typedef pair<int, int> pi;
    void distance(int i, vector<int> &dist, vector<int> adj[]){
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, i});
        dist[i]=0;
        while(!pq.empty()){
            auto itr=pq.top();
            int dis=itr.first;
            int node=itr.second;
            pq.pop();
            for(auto it:adj[node]){
                if(1+dis<dist[it]){
                    dist[it]=min(dist[it], 1+dis);
                    pq.push({dist[it], it});
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
        vector<int> dist1(n, 1e9);
        vector<int> dist2(n, 1e9);
        distance(node1, dist1, adj);
        distance(node2, dist2, adj);
        for(int i=0; i<n; i++){
            if(dist1[i]==1e9) dist1[i]=-1;
            if(dist2[i]==1e9) dist2[i]=-1;
        }
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