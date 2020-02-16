#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, rest = 0, proc = 0;
        for (int i = 0; i < gas.size(); ++i) {
            rest += gas[i] - cost[i];
            proc += gas[i] - cost[i];
            if (proc < 0) {
                start = i + 1;
                proc = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int res;
    res = sol.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0;
}