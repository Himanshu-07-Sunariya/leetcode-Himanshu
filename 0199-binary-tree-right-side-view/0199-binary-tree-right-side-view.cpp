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
    void helper(TreeNode* root,int lvl,vector <int>& ans){
        // base case
        if(!root) return;

        // main case
        if(lvl==ans.size()){
            ans.push_back(root->val);
        }

        // selfwork + recursive calls
        helper(root->right,lvl+1,ans);
        helper(root->left,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        // DFS approach
        if(!root) return {};

        vector <int> ans;
        int lvl=0;

        helper(root,lvl,ans);

        return ans;
    }
};