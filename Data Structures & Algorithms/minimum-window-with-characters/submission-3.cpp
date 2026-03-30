class Solution {
public:
    string minWindow(string s, string t) {
        // Min window for a set of letters
        // Approach -> iterate till we find all the letters then shrink from the left
        // The trick is that if we subtract all the rights it will be negative and vs just 0 if it's in the freq
        // We can check if we passed a t value if it turns positive again 
        vector<int> freq(128, 0);
        for (char c : t) ++freq[(unsigned char)c];

        int left = 0, missing = t.size(), minLength = INT_MAX;
        int bestStart = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (freq[(unsigned char)s[right]]-- > 0) --missing;
            while (missing == 0) {
                int length = right - left + 1;
                if (length < minLength) {
                    minLength = length;
                    bestStart = left;
                }
                if (++freq[(unsigned char)s[left++]] > 0) ++missing;
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(bestStart, minLength);
    }
};
