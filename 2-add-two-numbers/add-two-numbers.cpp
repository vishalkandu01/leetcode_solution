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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummy = dummyHead;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int sum = 0;
            sum += carry;
            if(l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            int lastDigit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(lastDigit);
            dummy -> next = newNode;
            dummy = dummy -> next;
        }
        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            dummy -> next = newNode;
        }
        return dummyHead -> next;
    }
};