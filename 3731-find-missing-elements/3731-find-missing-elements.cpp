class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map <int,int> mp;

        for(auto num:nums){
            mp[num]++;
        }

        vector <int> ans;

        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());

        for(int i=lo; i<=hi; i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};