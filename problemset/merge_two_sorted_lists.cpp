#include <iostream>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* ptr = res;
        while (l1) {
            if (l2 == NULL) {
                ptr->next = l1;
                ptr = ptr->next;
                return res->next;
            }
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        if (l2) {
            ptr->next = l2;
        }
        return res->next;
    }
};

int main() {
    Solution sol;
    int x = 2;
    ListNode* node1 = new ListNode(x);
    int y = 1;
    ListNode* node2 = new ListNode(y);
    ListNode* res = NULL;
    res = sol.mergeTwoLists(node1, node2);
    cout << res->next->val << endl;
    return 0;
}