class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check which part of the array is sorted left or right 
            if(nums[mid]==target) return mid;
            // left sorted 
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // when right part of array is sorted 
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    // target lies on the right half
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};