class Solution {
public:
    void merge(vector <int>& nums,int lo,int mid,int hi){
        int left=lo;
        int right=mid+1;

        // int cnt=0;

        vector <int> temp;

        while(left<=mid && right<=hi){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=hi){
            temp.push_back(nums[right++]);
        }

        for (int i = lo; i <= hi; i++) {
            nums[i] = temp[i - lo];
        }
        
        // return cnt;
    }

    void mergesort(vector <int>& nums,int lo,int hi,int& cnt){
        // base case
        if(lo>=hi) return;

        int mid=lo+(hi-lo)/2;

        mergesort(nums,lo,mid,cnt);
        mergesort(nums,mid+1,hi,cnt);

        // reverse pair comparison
        
        int right=mid+1;

        for(int left=lo; left<=mid; left++){

            while(right<=hi && 1LL*nums[left]>1LL*2*nums[right]){
                right++;
            }

            cnt+=right-(mid+1);
        }

        merge(nums,lo,mid,hi);
    }

    int reversePairs(vector<int>& nums) {
        // brute force approach
        int n=nums.size();

        int cnt=0;

        int left=0;
        int right=n-1;

        mergesort(nums,left,right,cnt);

        return cnt;
    }
};