class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // So we are just doing sliding window but the hard part is we have to keep track of the max as we go
        const int n = nums.size();
        if (k <= 0 || n == 0) return {};

        vector<int> ans;
        std::deque<int> dq; // property we are keeping is the decreasing order <- we will store indices but compare values
                            // we will use a deque allowing us to pop from both the back and front to achieve this 

        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back(); // keep the decreasing property
            dq.push_back(right);
            while (!dq.empty() && dq.front() < left) dq.pop_front(); // shrink the window is too large

            if (right - left + 1 == k) {  // if we are the correct window size
                ans.push_back(nums[dq.front()]);
                ++left;
            }
        }

        return ans;
    }
};
