#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next ? node->next->next : NULL;
        return;
    }
};

int main() {
    Solution sol;
    int x = 2;
    ListNode* xnode = new ListNode(x);
    int y = 3;
    ListNode* ynode = new ListNode(y);
    xnode->next = ynode;
    sol.deleteNode(xnode);
    return 0;
}