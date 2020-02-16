#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    labeler(grid, i, j); // label counted island
                    count++;
                }
            }
        }
        return count;
    }
    void labeler(vector<vector<char> >& grid, int posY, int posX) {
        // use depth-first-search to label counted island
        if (posY < 0 || posY >= grid.size() ||
           posX < 0 || posX >= grid[0].size() || grid[posY][posX] != '1') {
            return;
        }
        grid[posY][posX] = '2';
        labeler(grid, posY + 1, posX);
        labeler(grid, posY - 1, posX);
        labeler(grid, posY, posX + 1);
        labeler(grid, posY, posX - 1);
    }
};

int main() {
    vector<vector<char> > grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','1'},{'1','0','0','1','0'}};
    int res;
    Solution sol;
    res = sol.numIslands(grid);
    cout << res << endl;
    return 0;
}