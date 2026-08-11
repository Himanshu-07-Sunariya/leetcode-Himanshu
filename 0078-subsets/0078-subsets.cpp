class Solution {
public:
    void helper(int idx,vector <int> temp,vector<vector<int>>& ans,vector <int>& nums,int n){
        // base case
        if(idx>n) return;
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        // recursive calls
        // pick not pick method
        temp.push_back(nums[idx]);
        helper(idx+1,temp,ans,nums,n);
        temp.pop_back();

        helper(idx+1,temp,ans,nums,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        int idx=0;
        int n=nums.size();
        vector <int> temp;
        helper(idx,temp,ans,nums,n);

        return ans;
    }
};