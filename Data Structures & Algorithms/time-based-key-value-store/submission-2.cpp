class TimeMap {
private: 
    std::unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = timeMap[key];
        string ans = "";
        int left = 0, right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                ans = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
