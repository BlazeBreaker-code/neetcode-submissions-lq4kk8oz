class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];

            if (val == target) {
                return mid;
            } else if (val < nums[right]) { // right side sorted
                if (val < target && target <= nums[right]) left = mid + 1;
                else  right = mid - 1;
            } else { // left side sorted
                if (nums[left] <= target && target < val) right = mid - 1;
                else left = mid + 1;
            }
        }

        return -1;
    }
};
