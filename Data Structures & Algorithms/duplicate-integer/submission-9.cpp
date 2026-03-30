class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;

        for (int num : nums) {
            if (set.contains(num)) return true;
            set.insert(num);
        }

        return false;
    }
};