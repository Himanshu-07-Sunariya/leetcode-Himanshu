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
    bool isCousins(TreeNode* root, int x, int y) {
        // bfs
        if(!root) return false;

        queue <pair<TreeNode*,TreeNode*>> q;
        q.push({NULL,root});

        while(!q.empty()){
            // go level wise 
            int sz=q.size();
            bool foundx=false;
            bool foundy=false;
            TreeNode* parent1=NULL;
            TreeNode* parent2=NULL;

            for(int i=0; i<sz; i++){
                auto curr=q.front();
                q.pop();

                TreeNode* parent=curr.first;
                TreeNode* node=curr.second;

                if(node->val==x){
                    foundx=true;
                    parent1=parent;
                }

                if(node->val==y){
                    foundy=true;
                    parent2=parent;
                }

                // nbrs
                if(node->left){
                    q.push({node,node->left});
                }

                if(node->right){
                    q.push({node,node->right});
                }
            }

            if(foundx && foundy && parent1!=parent2){
                return true;
            }
            
            if(foundx && foundy && parent1==parent2 && parent1!=NULL){
                return false;
            }
        }

        return false;
    }
};