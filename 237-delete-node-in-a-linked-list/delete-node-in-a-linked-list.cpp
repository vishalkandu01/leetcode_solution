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
        // method-1;
        // ListNode* temp = node;
        // ListNode* temp2 = node -> next;
        // swap(temp->val, temp2->val);
        // temp -> next = temp2 -> next;
        // temp2 -> next = NULL;
        // return; 


        // method-2
        swap(node->val, node->next->val);
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
        return;
    }
};