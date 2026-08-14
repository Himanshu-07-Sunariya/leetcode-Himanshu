class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        int mid=0;

        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[lo++],nums[mid++]);
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[hi--]);
                // 2 uthaake bhja h to kch bawasir aya hoga handle it
            }
            else{
                mid++;
            }
        }
    }
};