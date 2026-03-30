class Solution {
public:
    bool isAnagram(string s, string t) {
        // An anagram is one that contains the same letters and freq 
        // Count the freq for both and if they match gg 

        if (s.size() != t.size()) return false;

        int charArr[26] = {0};

        for (int i = 0; i < s.size(); ++i) {
            ++charArr[s[i] - 'a'];
            --charArr[t[i] - 'a'];
        }

        for (int count : charArr) {
            if (count) return false;
        }

        return true;
    }
};
