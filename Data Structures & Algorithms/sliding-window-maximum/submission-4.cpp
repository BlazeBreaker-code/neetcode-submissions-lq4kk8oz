class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // We want to find the max at all times
        // We have to slide our window -> left to right
        // We will use a deque for this -> put elements in and pop from the back if the current element is greater than prev
        // else append if less than -> then check if it's within range and pop back values 

        const int n = nums.size();
        if (n == 0 || k == 0) return {};

        std::deque<int> dp;
        vector<int> ans;
        ans.reserve(n);

        int left = 0; // [] 
        for (int right = 0; right < n; ++right) {
            while (!dp.empty() && dp.back() < left) dp.pop_back();
            while (!dp.empty() && nums[dp.front()] <= nums[right]) dp.pop_front();

            dp.push_front(right);
            if (right - left + 1 == k) {
                ans.push_back(nums[dp.back()]);
                ++left;
            }
        }

        return ans;
    }
};
