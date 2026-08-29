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
    int ans=0;
    void helper(TreeNode* root,int x){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            x=x*10+root->val;
            ans+=x;
            return;
        }

        helper(root->left,x*10+root->val);
        helper(root->right,x*10+root->val);
    }

    int sumNumbers(TreeNode* root) {
        // base case
        if(!root) return 0;

        int x=0;
        helper(root,x);

        return ans;
    }
};