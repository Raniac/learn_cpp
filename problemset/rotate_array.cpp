#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        if (k == 0 || nums_size <= 1) return;
        int mk = k % nums_size;
        reverse(nums.begin(), nums.begin() + nums.size() - mk);
        reverse(nums.begin() + nums.size() - mk, nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 4;
    sol.rotate(nums, k);
    cout << nums[0] << endl;
    return 0;
}