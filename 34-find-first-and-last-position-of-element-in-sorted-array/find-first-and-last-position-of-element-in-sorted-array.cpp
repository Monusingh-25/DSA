class Solution {
    int lowerbound(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                // look for smaller index
                high=mid-1;
            }
            else{
                // look for right 
                low=mid+1;
            }
        }
         return ans;

    }
    
    int uppernbound(vector<int>& nums, int target){
         int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                // look for smaller index
                high=mid-1;
            }
            else{
                // look for right 
                low=mid+1;
            }
        }
         return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
       int lb=lowerbound(nums, target);
       if(lb==n || nums[lb]!=target) return {-1,-1};
       return {lb,uppernbound(nums, target)-1};

    }
};