#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (!fast) return head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // delete slow->next
        slow->next = slow->next->next;
        return head;
    }
};

int main() {
    Solution sol;
    int x = 1;
    ListNode* xnode = new ListNode(x);
    int y = 4;
    ListNode* ynode = new ListNode(y);
    int z = 1;
    ListNode* znode = new ListNode(z);
    xnode->next = ynode;
    ynode->next = znode;
    int n;
    ListNode* res;
    res = sol.removeNthFromEnd(xnode, n);
    return 0;
}