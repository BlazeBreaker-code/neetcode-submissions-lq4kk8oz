class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != val) nums[write++] = nums[right];
        }

        return write;
    }
};