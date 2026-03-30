class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};

        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) {
                ans.push_back(nums);
                return;
            }

            for (int j = i; j < nums.size(); ++j) {
                std::swap(nums[i], nums[j]);
                dfs(i + 1);
                std::swap(nums[i], nums[j]);
            }
        };

        dfs(0);
        return ans;
    }
};
