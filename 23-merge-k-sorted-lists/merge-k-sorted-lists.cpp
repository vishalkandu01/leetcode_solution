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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummy = dummyHead;
        while(left != NULL && right != NULL) {
            if(left -> val < right -> val) {
                dummy -> next = left;
                left = left -> next;
                dummy = dummy -> next;
            }
            else {
                dummy -> next = right;
                right = right -> next;
                dummy = dummy -> next;
            }
        }
        left != NULL ? dummy -> next = left : dummy -> next = right;
        return dummyHead -> next;
    }

    ListNode* mergeSolver(vector<ListNode*>& lists, int start, int end) {
        if(start == end) {
            return lists[start];
        }
        if(start+1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode* left = mergeSolver(lists, start, mid);
        ListNode* right = mergeSolver(lists, mid+1, end);
        return merge(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        // method-1
        // vector<int> v;
        // for(int i = 0; i < n; i++) {
        //     ListNode* temp = lists[i];
        //     while(temp != NULL) {
        //         v.push_back(temp -> val);
        //         temp = temp -> next;
        //     }
        // }
        // sort(v.begin(), v.end());
        // ListNode* dummyHead = new ListNode(-1);
        // ListNode* dummy = dummyHead;
        // for(int i = 0; i < v.size(); i++) {
        //     ListNode* newNode = new ListNode(v[i]);
        //     dummy -> next = newNode;
        //     dummy = dummy -> next;
        // }
        // return dummyHead -> next;


        // method-2
        if(n == 0) return NULL; 
        return mergeSolver(lists, 0, n-1);
    }
};