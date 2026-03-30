class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // hmm for this I think I understand 
        vector<int> max;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (right - left + 1 == k) {
                max.push_back(*std::max_element(nums.begin() + left, nums.begin() + right + 1));
                ++left;
            }
        }

        return max;
    }
};
