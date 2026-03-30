class Solution {
public:
    // We want to encode a string
    string encode(vector<string>& strs) {
        string res = "";
        for (const string s : strs) res += (to_string(s.size()) + "#") + s;
        return res;
    }

    // We want to decode that encoded string
    vector<string> decode(string s) {
        vector<string> res;
        int left = 0;
        while (left < s.size()) {
            int right = left;
            while (s[right] != '#') ++right;
            int length = stoi(s.substr(left, right - left)); 
            res.push_back(s.substr(right + 1, length));
            left = right + 1 + length;
        }

        return res;
    }
};
