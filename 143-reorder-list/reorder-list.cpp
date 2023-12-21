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
    void reorderList(ListNode* head) {
        // method-1
        // vector<ListNode*> v;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     v.push_back(temp);
        //     temp = temp -> next;
        // }
        // int i = 0;
        // int j = v.size()-1;
        // head -> next = v[j];
        // i++;
        // temp = head -> next;
        // while(i < j) {
        //     temp -> next = v[i];
        //     temp = temp -> next;
        //     j--;
        //     temp -> next = v[j];
        //     temp = temp -> next;
        //     i++;
        // }
        // temp -> next = NULL;
        // return;


        // method-2
        // vector<ListNode*> v;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     v.push_back(temp);
        //     temp = temp -> next;
        // }
        // int i = 1;
        // int j = v.size()-1;
        // temp = head;
        // while(i <= j) {
        //     temp -> next = v[j];
        //     temp = temp -> next;
        //     j--;
        //     temp -> next = v[i];
        //     temp = temp -> next;
        //     i++;
        // }
        // temp -> next = NULL;
        // return;


        // method-3
        if(head == NULL) return;
        ListNode* temp = head;
        ListNode* half = head;
        ListNode* prev = NULL;
        while(temp -> next != NULL && temp -> next -> next != NULL) {
            temp = temp -> next -> next;
            half = half -> next;
        }
        if(temp -> next != NULL) half = half -> next;
        while(half != NULL) {
            temp = half -> next;
            half -> next = prev;
            prev = half;
            half = temp;
        } 
        half = prev;
        while(head != NULL && half != NULL) {
            temp = head -> next;
            prev = half -> next;
            head -> next = half;
            half -> next = temp;
            head = temp;
            half = prev;
        }
        if(head != NULL && head -> next != NULL) {
            head -> next -> next = NULL;
        }
        return;
    }
};