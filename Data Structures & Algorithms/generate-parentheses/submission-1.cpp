class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        
        string curr;
        function<void(int, int)> dfs = [&](int open, int close) {
            if (curr.size() == 2 * n) {
                ans.push_back(curr);
                return;
            }

            if (open < n) {
                curr.push_back('(');
                dfs(open + 1, close);
                curr.pop_back();
            }

            if (close < open) {
                curr.push_back(')');
                dfs(open, close + 1);
                curr.pop_back();
            }

        };

        dfs(0, 0);
        return ans;
    }
};
