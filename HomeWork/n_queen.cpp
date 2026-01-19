#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<char>> grid;
    bool isSafe(int row, int col, int n) {
        // col check
        for(int i = row - 1; i >= 0; i--) {
            if(grid[i][col] == 'Q') return false;
        }
        // Diagonal Check
        for(int i = row - 1, j = col  + 1; i >= 0 && j < n; i--, j++) {
            if(grid[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(grid[i][j] == 'Q') return false;
        }
        return true;

    }

    void backTrack(int row, int n) {
        if(row == n) {
            vector<string> temp;
            for(int i = 0; i < n ;i++) {
                string str(grid[i].begin(), grid[i].end());
                temp.push_back(str);
            }
            result.push_back(temp);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, n)) {
                grid[row][col] = 'Q';
                backTrack(row + 1, n);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char>(n, '.'));
        backTrack(0, n);
        return result;
    }
};