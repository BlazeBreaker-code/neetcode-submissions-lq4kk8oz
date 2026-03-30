class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // Just return an array that is 2 of the prev
        vector<int> ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};