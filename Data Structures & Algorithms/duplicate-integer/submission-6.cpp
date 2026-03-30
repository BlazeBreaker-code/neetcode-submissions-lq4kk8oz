class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());

        if (seen.size() != nums.size()) return true; 
        return false;
    }
};