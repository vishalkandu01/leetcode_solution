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
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = NULL;
        
        while(cur != NULL) {
            temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        ListNode* temp = dummy;

        while(temp != NULL) {
            left--;
            right--;
            if(left == 0) temp1 = temp;
            if(right == 0) temp2 = temp;
            temp = temp -> next;
        }

        ListNode* end = temp2 -> next -> next;
        ListNode* newh = temp1 -> next;
        temp1 -> next = NULL;
        temp2 -> next -> next = NULL;
        newh = reverseList(newh);
        temp1 -> next = newh;
        while(newh -> next != NULL) {
            newh = newh -> next;
        }
        newh -> next = end;
        return dummy -> next;
    }
};