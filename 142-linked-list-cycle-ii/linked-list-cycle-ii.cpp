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
    ListNode *detectCycle(ListNode *head) {

        // Method 1
        // unordered_set<ListNode*> st;

        // while(head != NULL) {
        //     if(st.find(head) != st.end()) {
        //         return head;
        //     }

        //     st.insert(head);

        //     head = head -> next;
        // }

        // return NULL;


        // Method 2
        // if(head == NULL || head -> next == NULL) {
        //     return NULL;
        // }

        // ListNode* fast = head;
        // ListNode* slow = head;
        // ListNode* entry = head;

        // while(fast -> next != NULL && fast -> next -> next != NULL) {
        //     fast = fast -> next -> next;
        //     slow = slow -> next;
            
        //     if(slow == fast) {
        //         while(slow != entry) {
        //             slow = slow -> next;
        //             entry = entry -> next;
        //         }

        //         return slow;
        //     }
        // }

        // return NULL;



        // method-2 in another way
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};