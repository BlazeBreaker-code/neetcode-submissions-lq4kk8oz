class Solution {
public:
    int characterReplacement(string s, int k) {
        // Return the longest non repeating substr if you can perform k replacements
        // Need to keep track of the most freq val - length = replacements needed
        // if < k then we can change out maxLength else reduce
        // Need a freq array to track the max at each time

        std::unordered_map<char, int> freq;
        int left = 0, maxLength = 0, mostFreq = 0; 
        for (int right = 0; right < s.size(); ++right) {
            mostFreq = std::max(mostFreq, ++freq[s[right]]);
            while ((right - left + 1) - mostFreq > k) {
                --freq[s[left++]];
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
