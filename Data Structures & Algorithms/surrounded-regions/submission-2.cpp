class Solution {
public:
    void update(int i, int j, vector<vector<char>>& board){
        board[i][j] = 'X';
        if(i > 0 && board[i - 1][j] == 'O') update(i - 1, j, board);
        if(i < board.size() - 1 && board[i + 1][j] == 'O') update(i + 1, j, board);
        if(j > 0 && board[i][j - 1] == 'O') update(i, j - 1, board);
        if(j < board[i].size() - 1 && board[i][j + 1] == 'O') update(i, j + 1, board);
    }

    void traverse(int i, int j, bool& state, vector<vector<char>>& board){
        if(i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1) state = false;

        board[i][j] = '-';
        if(i > 0 && board[i - 1][j] == 'O') traverse(i - 1, j, state, board);
        if(i < board.size() - 1 && board[i + 1][j] == 'O') traverse(i + 1, j, state, board);
        if(j > 0 && board[i][j - 1] == 'O') traverse(i, j - 1, state, board);
        if(j < board[i].size() - 1 && board[i][j + 1] == 'O') traverse(i, j + 1, state, board);
        board[i][j] = 'O';
    }

    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O'){
                    bool state = true;
                    traverse(i, j, state, board);
                    if(state){
                        update(i, j, board);
                    }
                }
            }
        }
    }
};
