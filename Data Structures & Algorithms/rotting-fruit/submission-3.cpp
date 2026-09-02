class Solution {
public:

    struct Tri{
        int r;
        int c;
        int min = 0;
    };

    int orangesRotting(vector<vector<int>>& grid) {

        queue<Tri> q;        

        int total = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) total++;
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        total += q.size();

        int sol = 0;
        while(q.size() > 0){
            --total;
            Tri tri = q.front();
            int r = tri.r; int c = tri.c; int min = tri.min;
            sol = max(min, sol);
            if(r > 0 && grid[r - 1][c] == 1){
                grid[r - 1][c] = 2;
                q.push({r - 1, c, min + 1});
            }
            if(r < grid.size() - 1 && grid[r + 1][c] == 1){
                grid[r + 1][c] = 2;
                q.push({r + 1, c, min + 1});
            }
            if(c > 0 && grid[r][c - 1] == 1){
                grid[r][c - 1] = 2;
                q.push({r, c - 1, min + 1});
            }
            if(c < grid[0].size() - 1 && grid[r][c + 1] == 1){
                grid[r][c + 1] = 2;
                q.push({r, c + 1, min + 1});
            }
            q.pop();
        }
        return total == 0 ? sol : -1;

    }
};
