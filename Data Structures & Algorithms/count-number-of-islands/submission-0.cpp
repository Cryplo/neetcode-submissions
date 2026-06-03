class Solution {
public:

    void dfs(vector<vector<char>> &grid, int x, int y){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()){
            return;
        }
        if(grid[y][x] == '1'){
            grid[y][x] = '0';
            dfs(grid, x - 1, y);
            dfs(grid, x + 1, y);
            dfs(grid, x, y - 1);
            dfs(grid, x, y + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int sol = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1') sol++;
                if(grid[i][j] == '1') dfs(grid, j, i);
            }
        }
        return sol;
    }
};
