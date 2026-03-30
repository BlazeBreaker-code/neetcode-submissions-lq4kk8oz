class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> curr; // as we go
        function<void(int)> dfs = [&](int i) {
            if (i >= nums.size()) {
                ans.push_back(curr); // some will take all some will take none
                return;
            }

            curr.push_back(nums[i]); // take the value
            dfs(i + 1); // then call next value
            curr.pop_back(); // don't take the value
            dfs(i + 1); // then call next value
        };

        dfs(0);
        return ans;
    }
};
