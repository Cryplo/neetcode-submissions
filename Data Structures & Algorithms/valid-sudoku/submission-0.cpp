class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> box(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                   if(rows[i].count(board[i][j]) != 0
                   || columns[j].count(board[i][j]) != 0
                   || box[(j/3) + 3 * (i/3)].count(board[i][j]) != 0){
                    return false; 
                   } 
                   else{
                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                    box[(j/3) + 3 * (i/3)].insert(board[i][j]);
                   }
                }
            }
        }
        return true;
    }
};
