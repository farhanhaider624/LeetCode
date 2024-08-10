class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &vis){
        int n = matrix.size();
        int m = matrix[0].size();
        vis[r][c]=1;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0, 1};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c+ dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]==0 && !vis[nr][nc]){
                dfs(nr, nc, matrix, vis);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n*3, vector<int>(m*3, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
            }
        }
        int regions = 0;
        vector<vector<int>> vis(n*3, vector<int>(m*3, 0));
        for(int i=0; i<n*3; i++){
            for(int j=0; j<m*3; j++){
                if(matrix[i][j]==0 && !vis[i][j]){
                    dfs(i, j, matrix, vis);
                    regions++;
                }
            }
        }
        return regions;
    }
};