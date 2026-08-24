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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        // CBT method
        // indexing method but with bfs for level order
        queue <pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});

        unsigned long long maxWidth=0;

        while(!q.empty()){
            int sz=q.size();
            unsigned long long startIdx=-1;
            unsigned long long lastIdx=-1;

            for(int i=0; i<sz; i++){
                auto curr=q.front();
                q.pop();

                if(i==0) startIdx=curr.second;
                if(i==sz-1) lastIdx=curr.second;

                unsigned long long pi=curr.second;
                TreeNode* node=curr.first;

                if(node->left){
                    q.push({node->left,2*pi+1});
                }

                if(node->right){
                    q.push({node->right,2*pi+2});
                }
            }

            maxWidth=max(maxWidth,lastIdx-startIdx+1);
        }

        return (int)maxWidth;
    }
};