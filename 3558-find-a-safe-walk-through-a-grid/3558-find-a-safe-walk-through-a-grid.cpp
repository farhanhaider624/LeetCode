class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, -1, 0, 1};
    
    bool bfs(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health - grid[0][0]});
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [pos, currHealth] = q.front();
            q.pop();
            
            int r = pos.first, c = pos.second;
            
            if (r == m - 1 && c == n - 1 && currHealth > 0) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newHealth = currHealth - grid[nr][nc];
                    
                    if (newHealth > 0 && newHealth > visited[nr][nc]) {
                        visited[nr][nc] = newHealth;
                        q.push({{nr, nc}, newHealth});
                    }
                }
            }
        }
        
        return false;
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return bfs(grid, health);
    }
};
