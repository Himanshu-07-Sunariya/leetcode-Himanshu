class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // generate all subarrays
        // int maxElem=-1;
        unordered_map <int,int> mp;
        int n=nums.size();

        // sliding window
        // int left=0;
        // int right=0;
        // int n=nums.size();

        // while(left<n && right<n){
        //     // shrinking phase  
        //     while(right-left+1>3){
        //         left++;
        //     }

        //     // main case
        //     right++;
        // }

        // int maxElem=-1;

        for(int i=0; i+k<=n; i++){
            set <int> st;
            for(int j=i; j<i+k; j++){

                // if((j-i+1)<=k){
                st.insert(nums[j]);
                // }
            }

            for (auto x : st) {
                mp[x]++;
            }
        }

        int ans=-1;

        for(auto it:mp){
            if(it.second==1){
                ans=max(ans,it.first);
            }
        }

        return ans;
    }
};