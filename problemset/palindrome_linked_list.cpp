#include <iostream>

using namespace std;

/*
Given a singly linked list, determine if it is a palindrome.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while (fast) { // find middle node
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
        }
        while (slow){ // reverse
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        while (head && prev){ // check
            if (head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
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
    int z = 1;
    ListNode* znode = new ListNode(z);
    xnode->next = ynode;
    ynode->next = znode;
    bool res;
    res = sol.isPalindrome(xnode);
    cout << res << endl;
    return 0;
}