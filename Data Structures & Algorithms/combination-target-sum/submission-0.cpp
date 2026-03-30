class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        vector<int> curr;
        function<void(int, int)> dfs = [&](int i, int total) {
            if (total == target) {
                ans.push_back(curr);
                return;
            }

            if (i >= nums.size() || total > target) return;

            curr.push_back(nums[i]);
            dfs(i, total + nums[i]);
            curr.pop_back();
            dfs(i + 1, total);
        };

        dfs(0, 0);
        return ans;
    }
};
