class Solution {
public:
    bool horizontalCheck(vector<vector<char>>& board, int y) {

        unordered_map<char,int> exists;

        for(int i=0; i<9; i++) {
            if( board[y][i] == '.') continue;
            if( exists[board[y][i]] == 0 ) exists[board[y][i]] = 1;
            else return false;
        }
        return true;
    }

    bool verticalCheck(vector<vector<char>>& board, int x) {

        unordered_map<char,int> exists;

        for(int i=0; i<9; i++) {
            if( board[i][x] == '.') continue;
            if( exists[board[i][x]] == 0 ) exists[board[i][x]] = 1;
            else return false;
        }
        return true;
    }

    bool boxCheck(vector<vector<char>>& board, int x, int y) {

        unordered_map<char,int> exists;

        for( int i = x; i < x+3; i++) {
            for( int j = y; j < y+3; j++) {
                if( board[i][j] == '.') continue;
                if( exists[board[i][j]] == 0 ) exists[board[i][j]] = 1;
                else return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for(int i = 0; i< 9; i++){
            valid = valid && horizontalCheck(board,i);
            valid = valid && verticalCheck(board,i);
        }

        for(int i=0; i < 9; i=i+3) {
            for(int j=0; j < 9; j=j+3) {
                valid = valid && boxCheck(board, i, j);
            }
        }
        return valid;
    }
};
