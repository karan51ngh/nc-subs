class Solution {
public:

    bool backtrack(
    vector<vector<char>>& board, vector<vector<bool>>& visited, string &w, string &s, int i, int j) 
    {

        if (!(i >= 0 && i < board.size())) return false;
        if (!(j >= 0 && i < board[0].size())) return false;
        if(visited[i][j] == true) return false;

        if(board[i][j] != w[s.size()]) return false;

        s.push_back(board[i][j]);
        
        if (s == w) return true;
        visited[i][j] = true;

        if( backtrack(board, visited, w, s, i + 1, j) ) return true;
        if( backtrack(board, visited, w, s, i - 1, j) ) return true;
        if( backtrack(board, visited, w, s, i, j + 1) ) return true;
        if( backtrack(board, visited, w, s, i, j - 1) ) return true;

        s.pop_back();
        visited[i][j] = false;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

        if (word == "") return true;
        // 5. Declare string variable to pass as reference
        string current_path = "";

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if( backtrack(board, visited, word, current_path, i, j) ) return true;
            }
        }
        
        return false;
    }
};
