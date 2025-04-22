class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            // when left half is sorted 
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                // eliminate the search space after finding min 
                low=mid+1;
            }
            // when right half is sorted 
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};