/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode* head, ListNode* tail, int count) {
        ListNode* newnode = new ListNode(head -> val);

        if(head -> next == NULL) {
            if(head -> val != INT_MIN) tail -> next = newnode;
            return;
        }

        ListNode* temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
            if(head -> val != INT_MIN && head -> val == temp -> val) {
                temp -> val = INT_MIN;
                count++;
            }
            if(temp -> next == NULL && head -> val != INT_MIN && head -> val == temp -> val) {
                temp -> val = INT_MIN;
                count++;
            }
        }

        if(count == 1 && head -> val != INT_MIN) {
            tail -> next = newnode;
            tail = newnode;
        }

        solve(head -> next, tail, 1);
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head == NULL) {
        //     return NULL;
        // }
        // ListNode* newlist = new ListNode();
        // solve(head, newlist, 1);
        // return newlist -> next;


        if(head == NULL || head -> next == NULL) return head;
        ListNode* temp = head;
        map<int, int> mpp;
        while(temp != NULL) {
            mpp[temp -> val]++;
            temp = temp -> next;
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummy = dummyHead;
        for(auto nodeVal : mpp) {
            if(nodeVal.second == 1) {
                ListNode* node = new ListNode(nodeVal.first);
                dummy -> next = node;
                dummy = dummy -> next;
            }
        }
        return dummyHead -> next;
    }
};