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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        // Morris inorder traversal
        // we dont need anything for this

        TreeNode* curr=root;
        vector <int> ans;

        while(curr!=NULL){
            // main case
            if(curr->left==NULL){
                // inorder ko yehi chahiye
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                // predecessor
                TreeNode* pred=curr->left;

                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }

                // linking just
                if(pred->right==NULL){
                    // create thread
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    // link todo
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }

        return ans;
    }
};