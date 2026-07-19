class Solution {
public:
    bool isAnagram(string s, string t) {
        // True if both strings are anagrams of one another
        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(t.size());

        if (n != m) return false; // diff size
        vector<int> counts(26, 0);
        for (int i = 0; i < n; ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }

        for (int count : counts) {
            if (count != 0) return false;
        }

        return true;
    }
};
