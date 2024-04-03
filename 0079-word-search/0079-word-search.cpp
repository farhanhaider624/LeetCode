#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
private:
    bool f(vector<vector<char>>& board, string& word, int r, int c, int index) {
        if (index == word.size()) return true;
        
        int n = board.size();
        int m = board[0].size();
        
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != word[index]) return false;
        
        char temp = board[r][c]; 
        board[r][c] = '#';
        
        
        bool found = f(board, word, r + 1, c, index + 1) ||
                     f(board, word, r - 1, c, index + 1) ||
                     f(board, word, r, c + 1, index + 1) ||
                     f(board, word, r, c - 1, index + 1);
        
        board[r][c] = temp; 
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && f(board, word, i, j, 0)) 
                    return true;
            }
        }
        return false;
    }
};
