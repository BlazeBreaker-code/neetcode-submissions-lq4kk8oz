class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> countTasks(26, 0);
        for (char task : tasks) ++countTasks[task - 'A'];

        std::priority_queue<int> maxHeap;
        for (int count : countTasks) if (count > 0) maxHeap.push(count);

        std::queue<pair<int, int>> q; // task, time remaining

        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            ++time;
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1; maxHeap.pop();
                if (count > 0) q.push({count, time + n});
            } else {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
