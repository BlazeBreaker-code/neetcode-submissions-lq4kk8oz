class Solution {
public:
    int characterReplacement(string s, int k) {
        // what do we want to do? 
        // We want to check what the most freq char is
        // then subtract the total from that most freq char = numbers to swap
        // numbers to swap < k 
        // what do wewant to happen AAABABB 1 
        std::unordered_map<char, int> charFreq; 
        int left = 0, maxLength = 0, maxChar = 0;
        for (int right = 0; right < s.size(); ++right) {
            maxChar = std::max(maxChar, ++charFreq[s[right]]);
            while ((right - left + 1) - maxChar > k) {
                --charFreq[s[left++]];
                if (charFreq[s[left]] == 0) charFreq.erase(s[left]);
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
