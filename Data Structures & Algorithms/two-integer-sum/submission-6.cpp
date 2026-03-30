class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (seen.contains(comp)) return { seen[comp], i };
            seen[nums[i]] = i;
        }

        return {};
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)
