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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> verticalOrder;
        
        if(!root) return verticalOrder;

        map <int,map<int,multiset<int>>> mp;

        queue <pair<int,pair<int,TreeNode*>>> q;
        q.push({0,{0,root}});

        while(!q.empty()){
            // curr node
            auto curr=q.front();
            q.pop();

            int hd=curr.first;
            int lvl=curr.second.first;
            TreeNode* node=curr.second.second;

            mp[hd][lvl].insert(node->val);

            // nbrs
            if(node->left){
                q.push({hd-1,{lvl+1,node->left}});
            }

            if(node->right){
                q.push({hd+1,{lvl+1,node->right}});
            }
        }

        for(auto &hd:mp){

            vector <int> temp;

            for(auto &lvl:hd.second){
                
                for(auto &val:lvl.second){
                    temp.push_back(val);
                }
            }

            verticalOrder.push_back(temp);

        }

        return verticalOrder;

    }
};