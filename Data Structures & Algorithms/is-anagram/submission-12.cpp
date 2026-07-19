class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::array<int, 26> counts{};

        for (int i = 0; i < s.size(); ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }

        for (int count : counts) {
            if (count != 0) return false;
        } 

        return true;
    }
};
