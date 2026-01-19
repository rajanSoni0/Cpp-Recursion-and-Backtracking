#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> grid;
    int result;
    bool isSafe(int row, int col, int n) {
        for(int i =  row - 1; i >= 0; i--) {
            if(grid[i][col] == 'Q') return false;
        }
        for(int i =  row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(grid[i][j] == 'Q') return false;
        }
        for(int i =  row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(grid[i][j] == 'Q') return false;
        }

        return true;
    }
    void fun(int row, int n) {
        if(row == n) {
            result++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, n)) {
                grid[row][col] = 'Q';
                fun(row + 1, n);
                grid[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        result = 0;
        grid.resize(n, vector<char>(n, '.'));
        fun(0, n);
        return result;
    }
};