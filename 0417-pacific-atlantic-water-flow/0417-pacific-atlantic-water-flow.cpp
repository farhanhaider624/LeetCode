class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &heights, vector<vector<int>> &vis){
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j]=1;
        int delRow[]={-1, 0, 1, 0};
        int delCol[]={0, -1, 0, 1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0; i<4; i++){
                int nr=r+delRow[i];
                int nc=c+delCol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && 
                !vis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        //from top side of island
        for(int j=0; j<n; j++){
            bfs(0, j, heights, pacific);
        }
        //from left side of island
        for(int i=0; i<m; i++){
            bfs(i, 0, heights, pacific);
        }
        //from right side of island
        for(int i=0; i<m; i++){
            bfs(i, n-1, heights, atlantic);
        }
        //from bottom side of island
        for(int j=0; j<n; j++){
            bfs(m-1, j, heights, atlantic);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j]==1 && pacific[i][j]==atlantic[i][j]) 
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};