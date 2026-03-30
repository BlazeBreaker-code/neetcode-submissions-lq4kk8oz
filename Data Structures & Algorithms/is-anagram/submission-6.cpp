class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int charArr[26] = {0}; 
        for (int i = 0; i < s.size(); ++i) {
            ++charArr[s[i] - 'a'];
            --charArr[t[i] - 'a'];
        }

        for (const int& count : charArr) {
            if (count != 0) return false;
        }

        return true;
    }
};
