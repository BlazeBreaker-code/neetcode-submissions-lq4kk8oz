class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        function<void(int, int)> dfs = [&](int i, int total) {
            if (total == target) {
                ans.push_back(curr);
                return;
            }

            if (total > target || i >= candidates.size()) return;

            curr.push_back(candidates[i]);
            dfs(i + 1, total + candidates[i]);
            curr.pop_back();
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])  ++i;
            dfs(i + 1, total);
        };

        dfs(0,0);
        return ans;
    }
};
