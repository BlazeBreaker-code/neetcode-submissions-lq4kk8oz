class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

private: 
    void backtrack(vector<string>& res, string curr, int open, int close, int n) {
        if (curr.size() == 2 * n) { // we completed a string of parantheses
            res.push_back(curr);
            return;
        }

        if (open < n) { // 
            backtrack(res, curr + "(", open + 1, close, n);
        }

        if (close < open) {
            backtrack(res, curr + ")", open, close + 1, n);
        }
    }
};
