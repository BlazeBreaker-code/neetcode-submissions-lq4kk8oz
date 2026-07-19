class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currMax = -1;
        const int n = static_cast<int>(arr.size());
        for (int i = n - 1; i >= 0; --i) {
            const int curr = arr[i];
            arr[i] = currMax;
            currMax = std::max(currMax, curr);
        }

        return arr;
    }
};