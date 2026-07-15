#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) { // Floyd's Cycle-Finding Algorithm (also commonly referred to as the "Tortoise and the Hare" algorithm).
        // Edge case: an empty list or a single node cannot have a cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Moves 1 step
            fast = fast->next->next;    // Moves 2 steps
            
            // If they meet, there is definitely a cycle
            if (slow == fast) {
                return true;
            }
        }
        
        // If the fast pointer reaches the end, there is no cycle
        return false;
    }
};

int main() {
    Solution solver;

    // --- Test Case 1: Cyclic List (3 -> 2 -> 0 -> -4 -> back to 2) ---
    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creating the cycle back to node 2

    cout << boolalpha;
    cout << "Test 1 (Has Cycle): " << solver.hasCycle(head1) << " (Expected: true)" << endl;

    // --- Test Case 2: Acyclic List (1 -> 2 -> nullptr) ---
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Test 2 (Has Cycle): " << solver.hasCycle(head2) << " (Expected: false)" << endl;

    // Clean up memory for Test 2
    delete head2->next;
    delete head2;

    // Note: We avoid deleting nodes in Test 1 here because the circular 
    // references require manual breaking to avoid double-free errors.

    return 0;
}