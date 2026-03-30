class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        const int n = intervals.size();

        vector<vector<int>> merged;
        while (i < n && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i++]);
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }

        merged.push_back(newInterval);

        while (i < n) {
            merged.push_back(intervals[i++]);
        }

        return merged;
    }
};
