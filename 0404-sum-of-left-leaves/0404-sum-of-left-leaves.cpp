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
    int helper(TreeNode* root,int flag){
        // base case
        if(!root) return 0;
        if(root->left==NULL && root->right==NULL && flag==true) return root->val;

        // recursive calls
        int lft=helper(root->left,true);
        int ryt=helper(root->right,false);

        return lft+ryt;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        bool flag=true;
        return helper(root,flag);
    }
};