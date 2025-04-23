class Solution {
    private:
    int findmax(vector<int>& piles) {
        int maximum = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maximum = max(piles[i], maximum);
        }
        return maximum;
    }

    long long calculatetotalhour(vector<int>& piles, int hourly) {
        long long totalhour = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhour += ceil((double)piles[i] / (double)hourly);
        }
        return totalhour;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhour = calculatetotalhour(piles, mid); 
            if (totalhour <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};