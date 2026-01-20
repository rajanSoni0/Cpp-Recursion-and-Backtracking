#include<iostream>
#include<vector>
using namespace std;
int m, n;
void helper(string &temp, int i, int j) {
    if(i == m - 1 && j == n - 1) {
        cout << temp << " ";
        return;
    }
    
    if(i >= 0 && i < m && j >= 0 && j < n) {
        temp.push_back('R');
        helper(temp, i, j + 1);
        temp.pop_back();
        temp.push_back('D');
        helper(temp, i + 1, j);
        temp.pop_back();
    }
    
}

int main() {
    m = 3, n = 3;
    string temp = "";
    helper(temp, 0, 0);
}