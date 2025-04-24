class Solution {
public:
   int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int duplicate = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many numbers are ≤ mid
            int count = 0;
            for (int i=0;i<nums.size();i++) {
                if (nums[i] <= mid) count++;
            }

            if (count > mid) {
                duplicate = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return duplicate;
    }
};