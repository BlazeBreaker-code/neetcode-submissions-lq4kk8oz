class Twitter {
private:
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
    std::unordered_map<int, std::unordered_set<int>> followMap;
    std::unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId); // Make sure they are following themselves

        vector<int> ans; 
        // here is the hard part -> we want to take the 10 most recent tweets from him or his followers
        // We would want to first sort all the tweets by time -> pushing them into a heap
        // then as we go to the next index of the list 
        std::priority_queue<TweetNode> maxHeap;

        for (int followeeId : followMap[userId]) {
            auto& tweetList = tweetMap[followeeId];
            if (tweetList.empty()) continue;
            int index = tweetList.size() - 1;
            auto [time, tweetId] = tweetList[index];
            maxHeap.push({followeeId, tweetId, time, index});
        }

        // Now we want to take that top element and then keep looking at the next in the list
        while (ans.size() < 10 && !maxHeap.empty()) {
            auto [followeeId, tweetId, time, index] = maxHeap.top(); maxHeap.pop();
            ans.push_back(tweetId);
            if (index > 0) {
                auto [time, tweetId] = tweetMap[followeeId][--index];
                maxHeap.push({followeeId, tweetId, time, index});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].contains(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};
