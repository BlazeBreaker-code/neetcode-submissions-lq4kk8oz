class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : set) {
            if (!set.contains(num - 1)) {
                int length = 1;
                while (set.contains(num + length)) ++length;
                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};
