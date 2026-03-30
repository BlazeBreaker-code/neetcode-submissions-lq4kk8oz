class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // slowest we can eat
        int right = *max_element(piles.begin(), piles.end()); // fastest we can eat
        int res = right; // lets default to the fastest

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int totalTime = 0; // total time taken to finish the pile

            for (int pile : piles) totalTime += (pile + mid - 1) / mid; // Guess using the middle speed
            if (totalTime <= h) { // if the total time is less than the limit -> then it's correct lets see if we can edge closer by moving our right-> 
                res = mid;
                right = mid - 1; // try to slow it down by using a smaller mid number to guess
            } else {
                left = mid + 1; // else try to speed up using a higher mid number 
            }
        }

        return res;
    }
};
