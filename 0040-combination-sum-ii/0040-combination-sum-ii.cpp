class Solution {
public:
    // vector<vector<int>> result;

    // void helper(vector<int>& candidates,vector <int> &ans, int target,int cnt){
    //     //+ve base case
    //     if(target==0){
    //         result.push_back(ans);
    //         return;
    //     }
    //     //-ve base case
    //     if(target<0){
    //         return;
    //     }

    //     //duplicate case handle by permutation2 method...

    //     int curr=0; 
    //     //self work + recursive call
    //     for(int i=cnt; i<candidates.size(); i++){
    //         if(candidates[i]==curr){
    //             continue;
    //         }

    //         curr=candidates[i];
    //         //topi pehnao
    //         ans.push_back(candidates[i]);

    //         helper(candidates,ans,target-candidates[i],i+1);

    //         ans.pop_back();
    //     }
    // }

    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     vector <int> ans;
    //     int cnt=0;
    //     sort(candidates.begin(),candidates.end());

    //     helper(candidates,ans,target,cnt);

    //     return result;
    // }

    vector<vector<int>> result;

    void helper(int index,int target,vector <int> &candidates,vector <int> &ans,int prev){
        //+ve base case
        if(index==candidates.size() && target==0){
            result.push_back(ans);
            return;
        }

        //-ve base case
        if(index==candidates.size() && target!=0){
            return;
        }

        //-ve base case handeled and traverse fully on array 
        //applying pick and not pick method
        if(candidates[index]<=target && prev!=candidates[index]){
            //topi pehnao
            ans.push_back(candidates[index]);

            helper(index+1,target-candidates[index],candidates,ans,prev);

            //topi utaaro
            ans.pop_back();
        }

        //not pick  case
        //not repeat case handeled
        helper(index+1,target,candidates,ans,candidates[index]);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> ans;
        int index=0;
        sort(candidates.begin(),candidates.end());

        int prev=0;

        helper(index,target,candidates,ans,prev);

        return result;
    }
};