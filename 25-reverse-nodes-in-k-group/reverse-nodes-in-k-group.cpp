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
    int getLength(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head -> next;
        }
        return len;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;

        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = currNode -> next;
        
        int length = getLength(head);
        if(length < k) return head;

        int count = 0;
        while(count < k) {
            nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            count++;
        }

        if(nextNode != NULL) {
            head -> next = reverseKGroup(nextNode, k);
        }

        return prevNode;
    }
};