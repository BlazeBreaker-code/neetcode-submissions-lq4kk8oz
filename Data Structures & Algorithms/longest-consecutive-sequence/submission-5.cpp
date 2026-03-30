class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // to find the length of the longest consecutive numbers we can just use a set
        std::unordered_set<int> set(nums.begin(), nums.end());
        int maxCount = 0;
        for (int num : nums) {
            if (!set.contains(num - 1)) {
                int length = 1;
                while (set.contains(num + length)) ++length;
                maxCount = std::max(maxCount, length);
            } 
        }

        return maxCount;
    }
};
