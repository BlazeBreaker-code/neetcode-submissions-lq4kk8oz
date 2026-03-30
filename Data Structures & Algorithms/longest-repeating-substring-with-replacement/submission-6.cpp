class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;
        int left = 0, longest = 0, mostFreq = 0;
        for (int right = 0; right < s.size(); ++right) {
            mostFreq = std::max(mostFreq, ++freq[s[right]]);
            while ((right - left + 1) - mostFreq > k) {
                --freq[s[left++]];
            }

            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};
