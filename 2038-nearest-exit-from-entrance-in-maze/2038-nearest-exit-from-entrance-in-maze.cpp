class Solution {
public:
    using ppi = pair<int, pair<int, int>>;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<ppi> pq;
        pq.push({0, {entrance[0], entrance[1]}});
        vis[entrance[0]][entrance[1]]=1;
        int delRow[]={-1, 0, 1, 0};
        int delCol[]={0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if((r==0 || r==n-1 || c==0 || c==m-1) && (r!=entrance[0] || c!=entrance[1])){
                return steps;
            }
            for(int i=0; i<4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({steps+1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};