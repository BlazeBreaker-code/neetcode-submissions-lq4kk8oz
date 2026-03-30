class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Given an array of piles of bananas
        // Given number of hours to eat all the bananas
        // You make decide on an eating rate and each hour u must eat at that rate
        // If the pile has less then that rate unfort u are stuck for the hour still
        // What is the min eating rate to eat all the piles within h hours
        // We can use binary search and sort through rates 1 - max rate -> which would be the largest pile

        int left = 1, right = *max_element(piles.begin(), piles.end());
        int minRate = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalTime = 0;

            for (int pile : piles) {
                totalTime += std::ceil((double)pile / mid);
            }

            if (totalTime <= h) {
                minRate = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minRate;
    }
};
