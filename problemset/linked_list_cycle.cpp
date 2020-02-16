#include <iostream>

using namespace std;

/*
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)   return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != slow){
            if (fast->next == NULL || fast->next->next == NULL) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int x = 1;
    ListNode* xnode = new ListNode(x);
    int y = 4;
    ListNode* ynode = new ListNode(y);
    int z = 5;
    ListNode* znode = new ListNode(z);
    xnode->next = ynode;
    ynode->next = znode;
    // znode->next = ynode;
    bool res;
    res = sol.hasCycle(xnode);
    cout << res << endl;
    return 0;
}