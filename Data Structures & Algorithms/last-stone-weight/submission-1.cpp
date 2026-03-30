class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, vector<int>> maxHeap;
        for (int stone : stones) maxHeap.push(stone);
        while (maxHeap.size() > 1) {
            int s1 = maxHeap.top(); maxHeap.pop();
            int s2 = maxHeap.top(); maxHeap.pop();

            int diff = std::abs(s1 - s2);
            if (diff) maxHeap.push(diff);
        }

        maxHeap.push(0); // in case we destory all stones
        return maxHeap.top();
    }
};
