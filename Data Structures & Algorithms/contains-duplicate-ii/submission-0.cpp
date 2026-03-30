class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> seen;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (right - left > k) seen.erase(nums[left++]);
            if (seen.contains(nums[right])) return true;
            seen.insert(nums[right]);
        }

        return false;
    }
};