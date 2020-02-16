#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return builder(nums, 0, n - 1);
    }
    TreeNode* builder(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = builder(nums, l, m - 1);
        node->right = builder(nums, m + 1, r);
        return node;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {};
    TreeNode* res;
    res = sol.sortedArrayToBST(nums);
    return 0;
}
