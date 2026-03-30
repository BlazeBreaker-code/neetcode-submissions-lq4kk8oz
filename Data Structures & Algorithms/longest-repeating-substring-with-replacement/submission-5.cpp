class Solution {
public:
    int characterReplacement(string s, int k) {
        // We need to keep track of the most freq val at the time
        // since anything other than that will be our replacements
        std::unordered_map<char, int> freq;
        int left = 0, maxLength = 0, maxFreq = 0;
        for (int right = 0; right < s.size(); ++right) {
            maxFreq = std::max(maxFreq, ++freq[s[right]]);
            while ((right - left + 1) - maxFreq > k) {
                --freq[s[left++]];
            }
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
