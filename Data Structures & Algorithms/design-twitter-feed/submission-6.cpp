class Twitter {
private:
    std::unordered_map<int, std::unordered_set<int>> followMap;
    std::unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time = 0;

    struct TweetNode {
        int followeeId; 
        int tweetId;
        int time;
        int index;

        bool operator<(const TweetNode& other) const {
            return time < other.time;
        }
    };

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId); // make sure we are following ourself

        vector<int> ans;
        std::priority_queue<TweetNode> maxHeap;

        for (int followeeId : followMap[userId]) {
            if (tweetMap[followeeId].empty()) continue;

            int index = tweetMap[followeeId].size() - 1;
            auto [time, tweetId] = tweetMap[followeeId][index];
            maxHeap.push({followeeId, tweetId, time, index});
        }

        while (ans.size() < 10 && !maxHeap.empty()) {
            auto [followeeId, tweetId, _, index] = maxHeap.top(); maxHeap.pop();
            ans.push_back(tweetId);
            if (index > 0) {
                auto [nextTime, nextTweetId] = tweetMap[followeeId][--index];
                maxHeap.push({followeeId, nextTweetId, nextTime, index});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
