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
    bool compare(TreeNode* root,TreeNode* subRoot){
        // base case
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        return (root->val==subRoot->val)&&compare(root->left,subRoot->left)&&compare(root->right,subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // find
        // is same
        if(root==NULL) return false;

        bool ans=false;
        if(root->val==subRoot->val){
            ans=compare(root,subRoot);
        }

        return ans||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};