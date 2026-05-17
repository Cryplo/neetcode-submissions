class Solution {
public:
    bool recurs(int r, int c, int next, string word, vector<vector<char>>& board){
        cout << r << " " << c << endl;
        if(next == word.size()) return true;
        bool a = false;
        bool b = false;
        bool z = false;
        bool d = false;
        if(r != 0 && board[r - 1][c] == word[next]){
            vector<vector<char>> tempBoard = board;
            tempBoard[r-1][c] = ' ';
            a = recurs(r-1, c, next + 1, word, tempBoard);
        }   
        if(r != board.size() - 1 && board[r + 1][c] == word[next]){
            vector<vector<char>> tempBoard = board;
            tempBoard[r+1][c] = ' ';
            b = recurs(r+1, c, next + 1, word, tempBoard);
        }    
        if(c != 0 && board[r][c - 1] == word[next]){
            vector<vector<char>> tempBoard = board;
            tempBoard[r][c-1] = ' ';
            z = recurs(r, c - 1, next + 1, word, tempBoard);
        }    
        if(c != board[r].size() - 1 && board[r][c + 1] == word[next]){
            vector<vector<char>> tempBoard = board;
            tempBoard[r][c+1] = ' ';
            d = recurs(r, c + 1, next + 1, word, tempBoard);
        }
        return a || b || z || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0] && recurs(i, j, 1, word, board)) return true;
            }
        }
        return false;
    }
};
