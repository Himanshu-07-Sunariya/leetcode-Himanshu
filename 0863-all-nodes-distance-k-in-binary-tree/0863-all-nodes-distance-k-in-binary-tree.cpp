/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // bool findNode(TreeNode* root,TreeNode* target){
    //     // base case
    //     if(!root) return false;

    //     // selfwork + recursive call
    //     if(root->val==target->val){
    //         helper(root,ans,k);
    //         return true;
    //     }
    //     else{
    //         bool lft=false;
    //         bool ryt=false;

    //         if(root->left){
    //             lft=findNode(root->left,target);
    //         }

    //         if(root->right){
    //             ryt=findNode(root->right,target);
    //         }

    //         return lft||ryt;
    //     }

    //     return false;
    // }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <int> ans;

        if(!root) return ans;

        // har node k parents store krlo
        unordered_map <TreeNode*,TreeNode*> mp;

        queue <pair<TreeNode*,TreeNode*>> q;
        // TreeNode* parent=new TreeNode(-1);
        q.push({root,NULL});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            mp.insert({curr.first,curr.second});

            TreeNode* node=curr.first;

            // nbrs
            if(node->left){
                q.push({node->left,node});
            }

            if(node->right){
                q.push({node->right,node});
            }
        }

        // now traverse to find elements at k distance
        // now this tree behaves like the undirected graph so for the traversal we need visited array
        unordered_map <TreeNode*,bool> visited;
        queue <pair<int,TreeNode*>> q1;

        q1.push({k,target});
        visited[target]=true;

        while(!q1.empty()){
            // curr node
            auto curr=q1.front();
            q1.pop();

            // selfwork
            int dist=curr.first;
            TreeNode* node=curr.second;
            TreeNode* prnt=mp[node];

            if(dist==0){
                ans.push_back(node->val);
                continue;
            }

            // nbrs
            if(node->left && !visited.count(node->left)){
                visited[node->left]=true;
                q1.push({dist-1,node->left});
            }

            if(node->right && !visited.count(node->right)){
                visited[node->right]=true;
                q1.push({dist-1,node->right});
            }

            if(mp[node] && !visited.count(mp[node])){
                visited[mp[node]]=true;
                q1.push({dist-1,prnt});
            }
        }

        return ans;
    }
};