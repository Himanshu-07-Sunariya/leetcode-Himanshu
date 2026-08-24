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
    pair <int,int> dia_height(TreeNode* root){
        // base case
        if(!root){
            return make_pair(0,0);
        }

        // left part
        pair <int,int> lft=dia_height(root->left);
        pair <int,int> ryt=dia_height(root->right);

        // main work
        int ld=lft.first;
        int rd=ryt.first;
        int dia=lft.second+ryt.second;

        pair <int,int> ans;
        ans.first=max(dia,max(ld,rd));
        ans.second=1+max(lft.second,ryt.second);

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        return dia_height(root).first;
    }
};