class Solution {
    private:
       int sumbydivisor(vector<int>& nums,int d) {
        int n = nums.size();
        int sum=0;
        for (int i = 0; i < n; i++) {
            sum+=ceil((double)(nums[i]) / (double) (d));
             }
        return sum;
   }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int  maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        int low = 1, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
             if (sumbydivisor(nums, mid) <= threshold) {
                high = mid - 1;
            }
             else {
                low = mid + 1;
            }
        }
        return low;

    }
};