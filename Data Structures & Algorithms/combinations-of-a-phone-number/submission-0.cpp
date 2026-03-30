class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        vector<string> digitsToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

        string curr;
        function<void(int)> dfs = [&](int i) {
            if (i == digits.size()) {
                ans.push_back(curr);
                return;
            }

            string chars = digitsToChar[digits[i] - '0'];
            for (char c : chars) {
                curr.push_back(c);
                dfs(i + 1);
                curr.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};
