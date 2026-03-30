class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += (to_string(s.size()) + "#") + s; 
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int left = 0;
        while (left < s.size()) {
            int length = 0;
            while (left < s.size() && std::isdigit(s[left])) {
                length = length * 10 + (s[left] - '0');
                ++left;
            }
            res.push_back(s.substr(left + 1, length));
            left += length + 1;
        }

        return res;
    }
};
