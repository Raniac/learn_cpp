#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res = {};
        vector<int> row;
        if (numRows == 0) return res;
        row = {1};
        res.push_back(row);
        if (numRows == 1) return res;
        for (int i = 1; i < numRows; i++) {
            row = {1};
            for (int j = 1; j < i; j++) {
                row.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int> > res;
    res = sol.generate(numRows);
    for (auto c : res) {
        for (auto d : c) {
            cout << d;
        }
        cout << endl;
    }
    return 0;
}