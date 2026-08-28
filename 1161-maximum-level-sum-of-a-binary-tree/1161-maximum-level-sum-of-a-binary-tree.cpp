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
    int maxLevelSum(TreeNode* root) {
        // edge case
        if(!root) return 0;

        queue <pair<int,TreeNode*>> q;
        q.push({1,root});

        int maxSum=INT_MIN;
        int level=-1;

        while(!q.empty()){
            // level wise
            int sz=q.size();
            int sum=0;
            int lvl=-1;

            for(int i=0; i<sz; i++){
                // curr node
                auto curr=q.front();
                q.pop();

                lvl=curr.first;
                TreeNode* node=curr.second;

                sum+=node->val;

                if(node->left){
                    q.push({lvl+1,node->left});
                }

                if(node->right){
                    q.push({lvl+1,node->right});
                }
            }

            if(sum>maxSum){
                maxSum=sum;
                level=lvl;
            }
        } 

        return level;
    }
};