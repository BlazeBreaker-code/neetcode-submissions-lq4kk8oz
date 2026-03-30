class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int> seen;
        int left = 0, longest = 0;
        for (int right = 0; right < s.size(); ++right) {
            while (seen.contains(s[right])) {
                seen.erase(s[left++]);
            }
            seen.insert(s[right]);
            longest = std::max(longest, right - left + 1);
        }
        return longest;
    }
};
