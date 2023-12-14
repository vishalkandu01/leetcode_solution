/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* temp2 = node -> next;
        swap(temp->val, temp2->val);
        temp -> next = temp2 -> next;
        temp2 -> next = NULL;
        return; 
    }
};