#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class InorderTravSolution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inorderTraversal(root);
        vector<int> sortedList = inorderList;
        sort(sortedList.begin(), sortedList.end());
        sortedList.erase(unique(sortedList.begin(), sortedList.end()), sortedList.end());
        return sortedList == inorderList;
    }
    void inorderTraversal(TreeNode* root) {
        if (root->left) inorderTraversal(root->left);
        inorderList.push_back(root->val);
        if (root->right) inorderTraversal(root->right);
    }
private:
    vector<int> inorderList;
};

class InorderCompSolution {
public:
    int* last = NULL;
    bool isValidBST(TreeNode* root) {
        if (root){
            if(!isValidBST(root->left)) return false;
            if (last && *last>=root->val) return false;
            last = &root->val;
            if(!isValidBST(root->right)) return false;
            return true;
        }else return true;
    };
};

int main() {
    InorderCompSolution sol;
    int x = 1;
    TreeNode* root = new TreeNode(x);
    int y = 1;
    TreeNode* left = new TreeNode(y);
    int z = 3;
    TreeNode* right = new TreeNode(z);
    root->left = left;
    root->right = right;
    bool res = sol.isValidBST(root);
    cout << res << endl;
}