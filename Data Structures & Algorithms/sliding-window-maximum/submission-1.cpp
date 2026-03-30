class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        const int n = nums.size();
        if (n == 0 || k <= 0) return ans;

        std::deque<int> dq;

        for (int i = 0; i < n; ++i) {
            // First we want to remove anything out of the range
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // For deques we want to remove any values lower than our current one
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // If we have gotten to our window size we can start pushing maxes
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
