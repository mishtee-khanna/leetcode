#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle using Fast & Slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half in-place
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare first half and reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // Head of reversed second half
        bool palindrome = true;

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return palindrome;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}