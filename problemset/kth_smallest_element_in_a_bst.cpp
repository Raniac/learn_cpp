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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inordertrav;
        trav(root, k, inordertrav);
        return inordertrav[k-1];
    }
    void trav(TreeNode* node, int k, vector<int>& inordertrav) {
        if (!node) return;
        if (inordertrav.size() == k) return;
        trav(node->left, k, inordertrav);
        inordertrav.push_back(node->val);
        trav(node->right, k, inordertrav);
        return;
    }
};

class OptSolution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int lenLeft = 0;
        dfs(root->left, lenLeft);
        
        if(lenLeft >= k) return kthSmallest(root->left, k);
        if(lenLeft == k-1) return root->val;
        if(lenLeft < k) return kthSmallest(root->right, k-lenLeft-1);
        return -1; 
    }

    void dfs(TreeNode* root, int& len)
    {
        if(!root) return;
        len += 1;
        dfs(root->left, len);
        dfs(root->right, len);
    }
};

int main() {
    Solution sol;
    return 0;
}
