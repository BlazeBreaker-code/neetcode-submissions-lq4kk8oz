class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            maxHeap.push({dist, point});
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;
        ans.reserve(k);

        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
