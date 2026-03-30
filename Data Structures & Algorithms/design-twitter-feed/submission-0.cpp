class Twitter {
private:    
    struct TweetNode {
        int time;
        int tweetId;
        int userId;
        int idx;

        bool operator<(const TweetNode& other) const {
            return time < other.time;
        }
    };
    
public:
    int time = 0;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap; // {time, tweetId}

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId);

        priority_queue<TweetNode> maxHeap;

        for (int followeeId : followMap[userId]) {
            if (!tweetMap.count(followeeId) || tweetMap[followeeId].empty()) continue;

            int idx = tweetMap[followeeId].size() - 1;
            auto& [tweetTime, tweetId] = tweetMap[followeeId][idx];
            maxHeap.push({tweetTime, tweetId, followeeId, idx - 1});
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto [tweetTime, tweetId, followeeId, idx] = maxHeap.top();
            maxHeap.pop();

            res.push_back(tweetId);

            if (idx >= 0) {
                auto& [nextTime, nextId] = tweetMap[followeeId][idx];
                maxHeap.push({nextTime, nextId, followeeId, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};