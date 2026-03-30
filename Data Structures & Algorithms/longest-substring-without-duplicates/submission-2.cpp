class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // length of longest subset without dupl
        // Prob use a hashset
        std::unordered_set<char> set;
        int left = 0, maxLength = 0;
        for (int right = 0; right < s.size(); ++right) {
            while (set.contains(s[right])) {
                set.erase(s[left++]);
            }

            set.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
