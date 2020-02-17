#include <iostream>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> res = {};
        TreeNode* node = root;
        if (!root) return res;
        while (node || !nodes.empty()) {
            if (node) {
                nodes.push_back(node);
                node = node->left;
            }
            else {
                node = nodes.back();
                nodes.pop_back();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
