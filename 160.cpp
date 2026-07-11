#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        // Loop runs until the two pointers converge on the same node or both become nullptr
        while (ptrA != ptrB) {
            // If ptrA hits the end of List A, jump to the head of List B; otherwise, advance
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            
            // If ptrB hits the end of List B, jump to the head of List A; otherwise, advance
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        // Return either the intersecting node reference, or nullptr if no intersection exists
        return ptrA;
    }
};

int main() {
    Solution solver;

    // Manually constructing a test scenario
    // Shared Intersecting Path: 8 -> 4 -> 5
    ListNode* intersectNode = new ListNode(8);
    intersectNode->next = new ListNode(4);
    intersectNode->next->next = new ListNode(5);

    // List A Path: 4 -> 1 -> [8 -> 4 -> 5]
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersectNode;

    // List B Path: 5 -> 6 -> 1 -> [8 -> 4 -> 5]
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersectNode;

    // Find intersection
    ListNode* result = solver.getIntersectionNode(headA, headB);
    
    if (result != nullptr) {
        cout << "Intersected at node with value: " << result->val << " (Expected: 8)" << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}