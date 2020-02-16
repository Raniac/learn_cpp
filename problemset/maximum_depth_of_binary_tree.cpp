#include <iostream>
#include <vector>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        vector<int> depths;
        if (!root) return 0;
        else dfs(root, 0, depths);
        return *max_element(depths.begin(), depths.end());
    }
    void dfs(TreeNode* node, int depth, vector<int>& depths) {
        if (node) {
            depth += 1;
            dfs(node->left, depth, depths);
            dfs(node->right, depth, depths);
        } else {
            depths.push_back(depth);
            return;
        }
    }
};

class OneLineSolution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution sol;
    return 0;
}