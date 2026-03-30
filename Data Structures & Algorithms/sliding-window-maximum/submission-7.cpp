class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // [front = max, back = weak]
        const int n = nums.size(); 

        if (n == 0 || k == 0) return {};

        std::deque<int> dq;
        std::vector<int> ans;

        for (int right = 0; right < n; ++right) {
            while (!dq.empty() && dq.front() <= right - k) dq.pop_front(); // adjust window size
            while (!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back(); // maintain decreasing order
            dq.push_back(right); // push to our deque
            if (right >= k - 1) ans.push_back(nums[dq.front()]); // if we are of window size add to ans
        }

        return ans;
    }
};
