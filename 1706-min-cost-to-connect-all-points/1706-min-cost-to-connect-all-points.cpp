class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                    adj[i].push_back({j, wt});
                }
            }
        }
        vector<int> vis(n, 0);
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        int sum=0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto &it: adj[node]){
                int adjNode = it.first;
                int w = it.second;
                if(!vis[adjNode]){
                    pq.push({w, adjNode});
                }
            }
        }
        return sum;
    }
};