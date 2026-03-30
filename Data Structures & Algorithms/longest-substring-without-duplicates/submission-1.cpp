class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen; 
        int left = 0, maxLength = 0; 
        for (int right = 0; right < s.size(); ++right) {
            while (seen.count(s[right])) {
                seen.erase(s[left++]);
            }
            seen.insert(s[right]); 
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
