class Solution {
private:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) if (s[left++] != s[right--]) return false;
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> curr;

        function<void(int)> dfs = [&](int i) {
            if (i == s.size()) {
                ans.push_back(curr);
                return;
            }

            for (int j = i; j < s.size(); ++j) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub)) {
                    curr.push_back(sub);
                    dfs(j + 1);
                    curr.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};
