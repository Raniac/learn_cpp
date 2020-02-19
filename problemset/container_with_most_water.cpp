#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int shorter = 0;
        while (l < r) {
            shorter = min(height[l], height[r]);
            res = max(res, shorter * (r - l));
            if (height[l] > height[r]) {
                while (r >= l && height[r] <= shorter) r--;
            }
            else {
                while (l <= r && height[l] <= shorter) l++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int res;
    res = sol.maxArea(height);
    cout << res << endl;
    return 0;
}