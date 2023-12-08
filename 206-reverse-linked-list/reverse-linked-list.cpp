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
    void reverse(ListNode* &head, ListNode* currNode, ListNode* prevNode) {
        if(currNode == NULL) {
            head = prevNode;
            return;
        }
        reverse(head, currNode->next, currNode);
        currNode->next = prevNode;
    }

public:
    ListNode* reverseList(ListNode* head) {

        // method-1
        // ListNode* prevNode = NULL;
        // ListNode* currNode = head;
        // ListNode* nextNode = NULL;

        // while(currNode != NULL) {
        //     nextNode = currNode -> next;
        //     currNode -> next = prevNode;
        //     prevNode = currNode;
        //     currNode = nextNode;
        // }
        // return prevNode;


        // method-2
        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        reverse(head, currNode, prevNode);
        return head;
    }
};