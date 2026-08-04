class Solution {
public:
    void helper(int idx,int target,vector <int> temp,int n,vector<int>& candidates,vector<vector<int>>& combos){
        // base case
        if(target==0){
            combos.push_back(temp);
            return;
        }
        if(idx>=n || target<0){
            return;
        }

        // pick not pick unlimited time
        temp.push_back(candidates[idx]);
        helper(idx,target-candidates[idx],temp,n,candidates,combos);
        temp.pop_back();

        helper(idx+1,target,temp,n,candidates,combos);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combos;

        int idx=0;
        int n=candidates.size();

        vector <int> temp;

        helper(idx,target,temp,n,candidates,combos);

        return combos;
    }
};