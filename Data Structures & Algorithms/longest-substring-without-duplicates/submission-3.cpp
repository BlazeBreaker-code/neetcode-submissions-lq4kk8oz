class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set;

        int left = 0, maxLength = 0;
        for (int right= 0; right < s.size(); ++right) {
            while (set.contains(s[right])) set.erase(s[left++]);
            maxLength = std::max(maxLength, right - left + 1);
            set.insert(s[right]);
        }

        return maxLength;
    }
};
