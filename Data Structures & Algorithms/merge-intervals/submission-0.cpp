class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            auto& prev = merged.back();
            auto& curr = intervals[i];

            if (prev[1] >= curr[0]) {
                prev[1] = std::max(prev[1], curr[1]);
            } else {
                merged.push_back(curr);
            }
        }

        return merged;
    }
};
