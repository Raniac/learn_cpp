#include <iostream>

using namespace std;

/*
Reverse a singly linked list.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* revs = NULL;
        ListNode* curr = head;
        while (curr) {
            temp = curr->next;
            curr->next = revs;
            revs = curr;
            curr = temp;
        }
        return revs;
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
    ListNode* res;
    res = sol.reverseList(xnode);
    cout << res->val << endl;
    return 0;
}