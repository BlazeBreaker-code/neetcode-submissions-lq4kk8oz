class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // We want to 1, 2, 4, 6 -> 48, 24, 12, 8
        // The tricky part is we need to get the previous number to multiply
        // How about if we go forward -> 1, 1, 2, 8
        //  1, 2, 4, 6  now we do the same thing right side
        //  48, 24, 6, 1
        // now we just multiply with our other array
        // 48, 24, 12, 8

        vector<int> ans;
        ans.resize(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) { // we skip the first element since that will be one
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
