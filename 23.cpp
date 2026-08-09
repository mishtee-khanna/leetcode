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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(auto list : lists){
            if(list != nullptr) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            ListNode* minNode = pq.top();
            pq.pop();

            tail->next = minNode;
            tail = tail->next;

            if(minNode->next != nullptr) pq.push(minNode->next);
        }

        return dummy.next;
    }
};

int main() {
    Solution sol;

    // Create sample linked lists
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {list1, list2, list3};

    // Merge the k sorted linked lists
    ListNode* mergedList = sol.mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}