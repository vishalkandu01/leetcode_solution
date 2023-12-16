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
    int getDecimalValue(ListNode* head) {
        
        // method-1
        // vector<int> v;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     v.push_back(temp->val);
        //     temp = temp -> next;
        // }
        // reverse(v.begin(), v.end());
        // int ans = 0;
        // for(int i = 0; i < v.size(); i++) {
        //     ans += v[i] * pow(2, i);
        // }
        // return ans;


        // method-2
        ListNode* curr = head;
        ListNode *prev = NULL, *next = NULL;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        int ans = 0;
        int i = 0;
        curr = head;
        while(curr != NULL) {
            ans += curr->val * pow(2, i);
            i++;
            curr = curr -> next;
        }
        return ans;
    }
};