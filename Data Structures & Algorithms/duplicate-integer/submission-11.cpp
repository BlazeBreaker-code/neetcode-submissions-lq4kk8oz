class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        
        for (int num : nums) {
            if (seen.contains(num)) return true;
            seen.insert(num);
        }

        return false;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)