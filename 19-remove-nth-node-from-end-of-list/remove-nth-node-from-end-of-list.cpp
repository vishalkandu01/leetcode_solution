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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // method-1
        // int length = 0;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     length++;
        //     temp = temp -> next;
        // }
        // if(length == 1) return NULL;
        // if(length == n) return head -> next;
        // length -= n;
        // temp = head;
        // while(length > 1) {
        //     length--;
        //     temp = temp -> next;
        // }
        // temp -> next = temp -> next -> next;
        // return head;


        // method-2
        ListNode* dummyHead = new ListNode(-1);
        dummyHead -> next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return dummyHead -> next;
    }
};