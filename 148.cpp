#include <iostream>

using namespace std; 

// Standard LeetCode definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // Helper function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);        // Stack allocation: Type is 'ListNode'
        ListNode* tail = &dummy;  // Correctly initializes 'ListNode*' with '&dummy'
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append any remaining nodes
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        return dummy.next; // Correctly uses dot notation for stack object
    }

public:
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 elements are naturally sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Split the list using fast and slow pointers
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Disconnect the first half from the second half
        prev->next = nullptr;
        
        // Recursively sort the sub-lists
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Merge the sorted halves back together
        return merge(left, right);
    }
};

// Helper function to print the linked list in console
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solver;

    // Creating sample list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    head = solver.sortList(head);

    cout << "Sorted List:   ";
    printList(head); // Expected Output: 1 -> 2 -> 3 -> 4

    // Clean up heap allocations to prevent leaks
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}