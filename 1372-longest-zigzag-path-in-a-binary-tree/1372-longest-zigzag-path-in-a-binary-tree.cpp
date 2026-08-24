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
    int maxLen=0;
    void helper(TreeNode* root,string dir,int len){
        // base case
        if(!root) return;

        // main work
        maxLen=max(maxLen,len);

        if(dir=="left"){
            // continuation
            helper(root->right,"right",len+1);

            // not continued
            helper(root->left,"left",1);
        }
        else{
            // continuation
            helper(root->left,"left",len+1);

            // not continued
            helper(root->right,"right",1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        helper(root->left,"left",1);
        helper(root->right,"right",1);

        return maxLen;
    }
};