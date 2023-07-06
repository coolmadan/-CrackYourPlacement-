class Solution {
public:
    bool ans = false;

    void wordSearch(vector<vector<char>>& board, int row, int col, string& word, int i, vector<vector<bool>>& visited) {
        if (i == word.size()) {
            ans = true;
            return;
        }

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col])
            return;

        if (board[row][col] == word[i]) {
            visited[row][col] = true;

            wordSearch(board, row + 1, col, word, i + 1, visited);
            wordSearch(board, row - 1, col, word, i + 1, visited);
            wordSearch(board, row, col + 1, word, i + 1, visited);
            wordSearch(board, row, col - 1, word, i + 1, visited);

            visited[row][col] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    wordSearch(board, i, j, word, 0, visited);
                    if (ans)
                        return true;
                }
            }
        }
        return false;
    }
};
