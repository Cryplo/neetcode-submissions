class Solution {
public:
    void bfs(int x, int y, int & num, vector<vector<int>> & grid){
        num += 1;
        grid[x][y] = 0;
        if(x > 0 && grid[x - 1][y] == 1) bfs(x - 1, y, num, grid);
        if(x < grid.size() - 1 && grid[x + 1][y] == 1) bfs(x + 1, y, num, grid);
        if(y > 0 && grid[x][y - 1] == 1) bfs(x, y - 1, num, grid);
        if(y < grid[x].size() - 1 && grid[x][y + 1] == 1) bfs(x, y + 1, num, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sol = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int num = 0;
                    bfs(i, j, num, grid);
                    sol = max(sol, num);
                }
            }
        }
        return sol;
    }
};
