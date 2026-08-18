class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(n^3) approach
        int n=nums.size();
        // set<vector<int>> ans;

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector <int> temp({nums[i],nums[j],nums[k]});
        //                 sort(temp.begin(),temp.end());
        //                 ans.insert(temp);
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>> result(ans.begin(),ans.end());

        // return result;
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int left=i+1;
            int right=n-1;

            while(left<right){
                if(i==left) left++;
                if(i==right) right--;

                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    vector <int> temp({nums[i],nums[left],nums[right]});
                    ans.push_back(temp);

                    // skip duplicates in this as it is sorted
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }

                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }

                    left++;
                    right--;
                }
                else if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left++;
                }
            }
        }

        return ans;
    }
};