class Solution {
public:
    string minWindow(string s, string t) {
        // Hmm this is similiar to the prev problem but here we can't do
        // == since we could have a character in the middle
        // we could use .size() == 0 to see if we hit
        if (t.empty() || s.empty() || t.size() > s.size()) return ""; //  there is no way there can be a solution
        
        vector<int> charFreq(128, 0);
        for (int i = 0; i < t.size(); ++i) ++charFreq[(unsigned char)t[i]]; // map with t's character frequencies

        int bestLen = INT_MAX, bestStart = 0, missing = t.size();

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (charFreq[(unsigned char)s[right]]-- > 0) --missing;
            while (missing == 0) { // lets shrink our left side
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1; 
                    bestStart = left;
                }

                if (++charFreq[(unsigned char)s[left++]] > 0) ++missing;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
