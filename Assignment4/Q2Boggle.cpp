#include <bits/stdc++.h>
using namespace std; 

/*Boggle is a word game in which players compete to find the most words 
on a square grid of random letters. Valid words must be at least three 
characters and formed from non-overlapping (i.e., a position on the board 
can only be used once in a word) adjacent (including diagonal) letters. 
Given a Boggle board and a dictionary of valid words, return all valid 
words on the board.
*/

// Time Complexity: O(N) where N is the length and width of the square board
// Space Complexity: O(N) where N is the length and width of the square board

class Boggle {
public:
    //use BMI for constructor
    vector<vector<char>>& board;
    unordered_set<string>& dict;
    Boggle(vector<vector<char>>& board, unordered_set<string>& dict)
        : board(board), dict(dict) {}
    vector<string> findWords() {
        if (board.empty() || board[0].empty() || dict.empty()) {
            return {};
        }
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string curr;
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                helper(i, j, curr, visited, res);
            }
        }
        return res;
    }
    void helper(int row, int col, string curr, vector<vector<bool>>& visited, vector<string>& res) {
        //check dimensions (try adjacent and diagonal)
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col]) {
            return;
        }
        curr.push_back(board[row][col]);
        visited[row][col] = true;
        if (dict.find(curr) != dict.end() && curr.length() > 2) {
            res.push_back(curr);
        }
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                helper(i, j, curr, visited, res);
            }
        }
        curr.pop_back();
        visited[row][col] = false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A', 'D', 'E'},
            {'R', 'C', 'P'},
            {'L', 'A', 'Y'}
    };
    unordered_set<string> dict = {"ACE", "APE", "CAPE", "CLAP", "CLAY", "GAPE", "GRAPE", "LACE", "LAP", "LAY", "MACE", "MAP", "MAY", "PACE", "PAY", "RAP", "RAY", "TAP", "TAPE", "TRACE", "TRAP", "TRAY", "YAP"};
    Boggle game(board, dict);
    vector<string> res = game.findWords();
    for (auto word : res) {
        cout << word << " ";
    }
}