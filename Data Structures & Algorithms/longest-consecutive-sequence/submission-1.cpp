class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int maxLength = 0;
        for (const int& num : set) {
            if (!set.count(num - 1)) {
                int length = 1;
                while (set.count(num + length)) ++length;
                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};
