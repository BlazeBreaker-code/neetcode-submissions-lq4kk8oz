class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> charFreq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++charFreq[s[i] - 'a'];
            --charFreq[t[i] - 'a'];
        }

        for (const int& count : charFreq) {
            if (count != 0) return false;
        }

        return true;
    }
};
