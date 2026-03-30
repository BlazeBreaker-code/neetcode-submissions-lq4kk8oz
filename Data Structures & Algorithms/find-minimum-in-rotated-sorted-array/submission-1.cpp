class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) { // we just want to find the lower bound
            int mid = left + (right - left) / 2;
            int val = nums[mid];

            if (val < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
