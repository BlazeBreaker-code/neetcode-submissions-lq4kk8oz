class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += (to_string(s.size()) + "#" + s);
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] != '#') ++j;
            int length = stoi(s.substr(i, j));
            i = j + 1;
            decoded.push_back(s.substr(i, length));
            i += length;
        }

        return decoded;
    }
};
