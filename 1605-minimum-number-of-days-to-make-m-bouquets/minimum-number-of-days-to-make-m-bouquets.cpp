class Solution {
    private:
       bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int count = 0;
        int noOfbouquets = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    noOfbouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return noOfbouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long value=m* 1LL*k*1LL;
        if (value > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
};