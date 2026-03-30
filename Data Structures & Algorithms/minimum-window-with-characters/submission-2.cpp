class Solution {
public:
    string minWindow(string s, string t) {
        // Shortest substring of s containing all characters of t
        // We can just return substr to make it efficent
        if (t.size() > s.size()) return "";
        int left = 0, minLength = INT_MAX, missing = t.size();
        int minStart = 0;

        vector<int> arr(128, 0);
        for (char c : t) ++arr[(unsigned char)c];

        for (int right = 0; right < s.size(); ++right) {
            if (arr[(unsigned char)s[right]]-- > 0) {
                --missing;
                while (missing == 0) {
                    int length = right - left + 1;
                    if (length < minLength) {
                        minLength = length;
                        minStart = left;
                    }
                    if (++arr[(unsigned char)s[left++]] > 0) ++missing;
                }
            }
        }

        return (minLength != INT_MAX) ? s.substr(minStart, minLength) : "";
    }
};
