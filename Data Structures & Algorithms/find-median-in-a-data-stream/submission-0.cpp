class MedianFinder {
private: 
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, vector<int>, std::greater<int>> minHeap;

    // If we are an odd number total just return the top of the maxheap for the left
    // If we are an even number total add both the left max and right min together and divide by two 
    // This should be easy if we just keep rebalancing the sides

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        } 

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
    }
    
    double findMedian() {
        int n = maxHeap.size();
        int m = minHeap.size();

        if ((n + m) % 2 == 1) {
            return (double)maxHeap.top();
        } else {
            double i = (double)maxHeap.top();
            double j = (double)minHeap.top(); 
            return (i + j) / 2.0;
        }
    }
};
