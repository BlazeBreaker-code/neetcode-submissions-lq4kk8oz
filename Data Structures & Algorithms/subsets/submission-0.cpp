class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
            function<void(int)> dfs = [&](int i){
                if (i >= nums.size()) {
                    ans.push_back(curr);
                    return;
                }

                // decision to include nums[i]
                curr.push_back(nums[i]);
                dfs(i + 1);
                curr.pop_back();
                dfs(i + 1);
            };

        
        dfs(0);
        return ans;
    }
};
