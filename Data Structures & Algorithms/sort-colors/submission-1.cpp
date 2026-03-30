class Solution {
    // sort in place -> colors are grouped
    // There is a trick - sort 1 and 2 and 0 should be on the left
    // [1, 0, 2, 1]
    // [2, 1, 0, 1, 1, 2, 2]
    // [2, 1, 0, 1, 1, 2, 2]
    // [2, 1, 0, 1, 1, 2, 2]
    // [1, 1, 0, 1, 2, 2, 2]
    // []
public:
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = n - 1, i = 0;

        while(i <= right) {
            if (nums[i] == 0) std::swap(nums[left++], nums[i++]);
            else if (nums[i] == 2) std::swap(nums[right--], nums[i]);
            else ++i;
        }
    }
};