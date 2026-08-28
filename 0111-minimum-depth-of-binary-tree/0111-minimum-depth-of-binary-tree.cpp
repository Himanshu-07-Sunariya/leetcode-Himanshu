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
    void helper(TreeNode* root,int cnt,int& minHeight){
        //base case
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            minHeight=min(cnt,minHeight);
            return;
        }

        // recursive calls
        helper(root->left,cnt+1,minHeight);
        helper(root->right,cnt+1,minHeight);
    }

    int minDepth(TreeNode* root) {
        int minHeight=INT_MAX;
        int cnt=1;

        helper(root,cnt,minHeight);

        return (minHeight==INT_MAX)?0:minHeight;
    }
};