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
    bool isCompleteTree(TreeNode* root) {
        // base case
        if(!root) return true;

        queue <pair<unsigned long long,TreeNode*>> q;
        q.push({0,root});
        unsigned long long maxIdx=0;
        unsigned long long cnt=0;

        while(!q.empty()){
            // curr node
            auto curr=q.front();
            q.pop();
            cnt++;

            unsigned long long idx=curr.first;
            TreeNode* node=curr.second;

            maxIdx=max(maxIdx,idx);

            // nbrs
            if(node->left){
                q.push({2*idx+1,node->left});
            }

            if(node->right){
                q.push({2*idx+2,node->right});
            }
        }

        if(cnt-1==maxIdx) return true;
        return false;
    }
};