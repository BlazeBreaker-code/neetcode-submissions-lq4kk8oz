class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // figure out the frequencies, then build out the buckets and then build the res
        std::unordered_map<int, int> numFreq;
        for (const int& num : nums) ++numFreq[num];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : numFreq) buckets[freq].push_back(num);

        vector<int> res;
        res.reserve(k);

        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; --i) {
            for (const int& num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
