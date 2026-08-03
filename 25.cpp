#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes available
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head; 
            curr = curr->next;
        }

        // Step 2: Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        curr = head;
        
        for (int i = 0; i < k; ++i) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }


        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

int main() {
    Solution sol;

    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = sol.reverseKGroup(head, k);

    // Print the reversed list
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}