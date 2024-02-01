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
    ListNode* solve(ListNode* curr, ListNode* prev, ListNode* forw) {
        if(curr == NULL) return prev;
        forw = curr -> next;
        curr -> next = prev;

        // one way to write
        // prev = curr;
        // curr = forw;
        // return solve(curr, prev, forw);
        
        // another way to write
        return solve(forw, curr, forw);
    }

public:
    ListNode* reverseList(ListNode* head) {

        // method-1 -> iterative approach
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // ListNode* forw = NULL;
        // while(curr != NULL) {
        //     forw = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = forw;
        // }
        // return prev;

        // method-2 -> recrusive solution
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        return solve(curr, prev, forw); 
    }
};