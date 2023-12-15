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
    ListNode* middleNode(ListNode* head) {

        // method-1
        // int len = 0;
        // ListNode* temp = head;
        // if(head -> next == NULL) return head;
        // while(temp != NULL) {
        //     temp = temp -> next;
        //     len += 1;
        // }
        // len = len/2;
        // // cout << len;
        // temp = head;
        // while(len != 0) {
        //     temp = temp -> next;
        //     len -= 1;
        // }
        // return temp;


        // method-2
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
};