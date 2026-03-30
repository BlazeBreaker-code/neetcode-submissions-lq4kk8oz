class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // So we want to find the most freq elements of k = top 3, top 2, etc
        // We would use bucket sort

        // First we need a freq map
        std::unordered_map<int, int> map;
        for (int num : nums) ++map[num];

        // Then we need to store the freq based on index
        vector<vector<int>> buckets(nums.size() + 1); // + 1 just in case we only have one num in the array
        for (auto& [num, freq] : map) {
            buckets[freq].push_back(num);
        }

        // Now we just need to store k most freq and return it
        vector<int> ans;
        ans.reserve(k);

        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int element : buckets[i]) {
                ans.push_back(element);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
