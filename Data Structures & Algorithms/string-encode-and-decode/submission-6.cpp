class Solution {
public:

    string encode(vector<string>& strs) {
        // We want to have a number for the length of the string followed by # then the string
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            int length = 0;
            while (i < s.size() && std::isdigit(s[i])) length = length * 10 + (s[i++] - '0'); 
            decoded.push_back(s.substr(i + 1, length));
            i += (length + 1);
        }

        return decoded;
    }
};
