class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // sliding window with 2 freq arrays
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < s1.size(); ++i) { // build both lists
            ++s1Count[s1[i] - 'a'];
            ++s2Count[s2[i] - 'a'];
        }

        if (s1Count == s2Count) return true; // our first iteration matched

        int left = 0;
        for (int right = s1.size(); right < s2.size(); ++right) {
            ++s2Count[s2[right] - 'a'];
            --s2Count[s2[left++] - 'a'];
            if (s1Count == s2Count) return true;
        }

        return false;
    }
};
