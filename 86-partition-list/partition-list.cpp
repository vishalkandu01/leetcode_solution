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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        if(head -> val >= x) {
            ListNode* k1, *k2;
            k2 = head -> next;
            k1 = head;
            
            while(k2 && k2 -> val >= x) {
                k1 = k1 -> next;
                k2 = k2 -> next;
            }

            if(k2 != NULL) {
                k1 -> next = k2 -> next;
                k2 -> next = head;
                head = k2;
            }
        } 

        ListNode* l1, *l2, * l3;
        l1 = head;
        
        while(l1 && l1 -> next && l1 -> next -> val < x && l1 -> val < x) {
            l1 = l1 -> next;
        }

        if(l1 == NULL) {
            return head;
        }

        l2 = l1;
        l3 = l1 -> next;

        while(l3 && l2) {
            if(l3 -> val >= x) {
                l3 = l3 -> next;
                l2 = l2 -> next;
                continue;
            }

            l2 -> next = l3 -> next;
            l3 -> next = l1 -> next;
            l1 -> next = l3;
            l1 = l1 -> next;
            l3 = l2 -> next;
        }

        return head;
    }
};