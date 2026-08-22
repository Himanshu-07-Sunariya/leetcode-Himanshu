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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue <TreeNode*> q;
        q.push(root);
        bool lvl=true;

        while(!q.empty()){
            int n=q.size();
            vector <int> temp(n);

            for(int i=0; i<n; i++){
                auto curr=q.front();
                q.pop();

                int idx;
                if(lvl){
                    idx=i;
                }
                else{
                    idx=n-i-1;
                }

                temp[idx]=curr->val;

                // nbrs daalo
                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }

            lvl=!lvl;
            ans.push_back(temp);
        }

        return ans;
    }
};