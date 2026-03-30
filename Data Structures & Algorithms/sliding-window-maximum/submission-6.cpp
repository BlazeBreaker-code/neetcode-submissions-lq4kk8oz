class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // [front = newest, back = max] 
        std::deque<int> dq;
        vector<int> ans;

        for (int right = 0; right < nums.size(); ++right) {
            while (!dq.empty() && dq.back() <= right - k) dq.pop_back(); // get rid of out of range indexes
            while (!dq.empty() && nums[dq.front()] <= nums[right]) dq.pop_front(); // make sure our max is in the back 
            dq.push_front(right); // push our val

            // if we are at our limit push max to our array
            if (right >= k - 1) ans.push_back(nums[dq.back()]);
        }

        return ans;
    }
};
