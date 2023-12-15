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
        int len = 0;
        ListNode* temp = head;
        if(head -> next == NULL) return head;
        len += 1;
        while(temp != NULL) {
            temp = temp -> next;
            len += 1;
        }
        bool flag = false;
        if(len % 2 != 0) flag = true;
        len = len/2;
        // cout << len;
        temp = head;
        len -= 1;
        while(len != 0) {
            temp = temp -> next;
            len -= 1;
        }
        if(flag == false) return temp;
        return temp -> next;
    }
};