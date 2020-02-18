#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    class isGreater{ // reload function less()
    public:
       bool operator()(ListNode *a, ListNode *b){
          return a->val > b->val;
       }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, isGreater> heap;
        // priority_queue< int, vector<int>, greater<int> > q;  // least-top heap
        // priority_queue< int, vector<int>, less<int> > q;     // greatest-top heap
        for (auto p : lists) {
            if (p != NULL) {
                heap.push(p);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (!heap.empty()) {
            ListNode* top = heap.top();
            heap.pop();
            curr->next = top;
            curr = curr->next;
            if (top->next != NULL) {
                heap.push(top->next);
            } 
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};

int main() {
    Solution sol;
    int x = 2;
    ListNode* node1 = new ListNode(x);
    int y = 1;
    ListNode* node2 = new ListNode(y);
    ListNode* res = NULL;
    vector<ListNode*> lists;
    lists.push_back(node1);
    lists.push_back(node2);
    res = sol.mergeKLists(lists);
    cout << res->val << endl;
    return 0;
}