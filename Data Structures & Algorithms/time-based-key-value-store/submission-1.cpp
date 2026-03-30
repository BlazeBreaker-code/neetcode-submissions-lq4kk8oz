class TimeMap {
    // Time based key-value
    // Store different timestamps 
    // Retrieve key at specified timestamp
    // key -> value at timestamp
    // return the most recent value of the key 

/*
    Imagine you have a magic diary.

    The diary lets you:

    Write a word next to a name.

    Write the time when you wrote it.

    Later, ask:
    “What was the word for this name at time X?”

    But here’s the rule:

    You might change the word later.
    And every time you change it, the time is bigger than before.

    So time always moves forward.
    Never backward.
    No time travel chaos.
*/
private: 
    std::unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        // From here we will get the list for the key and then just do binary search
        auto& values = timeMap[key];
        string ans = "";
        int left = 0, right = values.size() - 1;

        while (left <= right) { // do lower bound search
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) { // valid
                ans = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
