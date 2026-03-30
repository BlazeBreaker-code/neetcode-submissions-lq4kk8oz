class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || t.size() > s.size()) return "";
        vector<int> charFreq(128, 0);
        for (const char& c : t) ++charFreq[(unsigned char)c];

        int left = 0, minLength = INT_MAX, bestStart = 0, missing = t.size();
        for (int right = 0; right < s.size(); ++right) {
            if (charFreq[(unsigned char)s[right]]-- > 0) --missing; // that mean we landed on the shared char.
            while (missing == 0) { // we have seen all the characters in t now lets try shortening it from the left side
                if (right - left + 1 < minLength) { // first lets see if this is our best length
                    minLength = right - left + 1;
                    bestStart = left;
                }

                if (++charFreq[(unsigned char)s[left++]] > 0) ++missing; // it would be greater than 0 if only we iterated on a shared char
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(bestStart, minLength);
    }
};
