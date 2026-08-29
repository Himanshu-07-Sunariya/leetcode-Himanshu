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
    int helper(TreeNode* root,int minVal,int maxVal){
        // base case
        if(!root) return 0;

        // selfwork + recursive calls
        int ans=max(abs(root->val-minVal),abs(root->val-maxVal));

        minVal=min(minVal,root->val);
        maxVal=max(maxVal,root->val);

        int lft=helper(root->left,minVal,maxVal);
        int ryt=helper(root->right,minVal,maxVal);

        return max(ans,max(lft,ryt));
    }

    int maxAncestorDiff(TreeNode* root) {
        // ancestors se max min difference min max value of ancestors se hi aega
        if(!root) return 0;

        int minVal=root->val;
        int maxVal=root->val;

        return helper(root,minVal,maxVal);
    }
};