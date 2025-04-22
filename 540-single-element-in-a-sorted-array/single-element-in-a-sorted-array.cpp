class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            // check in which part of the ans you are currently left or right 
            //  we are currently left part 
            if((mid%2==1&& nums[mid-1]==nums[mid]) ||(mid%2==0 && nums[mid]==nums[mid+1])) {
                // element will be on right half so eliminate left half 
                    low=mid+1;
            }
            else{
                // when we are currently on right half 
                high=mid-1; // eliminate right half
            }
        }
        return -1;
    }
};