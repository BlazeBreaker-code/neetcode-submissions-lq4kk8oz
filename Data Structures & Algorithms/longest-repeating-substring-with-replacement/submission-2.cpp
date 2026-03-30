class Solution {
public:
    int characterReplacement(string s, int k) {
        // so we need to do the total - maxChar = number of char needed to replace
        std::unordered_map<char, int> charFreq;
        
        int left = 0, maxLength = 0, maxChar = 0;
        for (int right = 0; right < s.size(); ++right) {
            maxChar = std::max(maxChar, ++charFreq[s[right]]);
            while ((right - left + 1) - maxChar > k) {
                --charFreq[s[left++]];
            }

            maxLength = std::max(maxLength, right - left + 1); 
        }

        return maxLength;
    }
    
};
