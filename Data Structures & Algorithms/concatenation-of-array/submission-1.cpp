class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> newNums(nums.begin(), nums.end());
        newNums.reserve(nums.size() * 2);
        newNums.insert(newNums.end(), nums.begin(), nums.end());
        return newNums;
    }
};