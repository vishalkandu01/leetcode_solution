/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr; 
    TreeNode* first = nullptr;
    TreeNode* sec = nullptr;

    void inorder(TreeNode* cur) {
        if(!cur) {
            return;
        }
        inorder(cur -> left);
        if(prev != NULL && cur -> val < prev -> val) {
            if(!first) {
                first = prev;
            }
            sec = cur;
        }
        prev = cur;
        inorder(cur -> right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first -> val;
        first -> val = sec -> val;
        sec -> val = temp;
    }
};