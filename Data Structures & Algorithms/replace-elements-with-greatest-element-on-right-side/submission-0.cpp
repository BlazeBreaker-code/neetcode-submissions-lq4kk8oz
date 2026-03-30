class Solution {
// since we are looking for the max right 
// just iterate from the right side and grab the max
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currMax = -1;
        for (int right = arr.size() - 1; right >= 0; --right) {
            int curr = arr[right];
            arr[right] = currMax; 
            currMax = std::max(currMax, curr);
        }

        return arr;
    }
};