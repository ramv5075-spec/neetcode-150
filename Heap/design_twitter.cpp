// NeetCode 150 - Heap / HashMap
// Problem: Design Twitter
// Difficulty: Medium
// Approach: Store all tweets in a list + Follow graph (HashSet)
// Time Complexity:
//   postTweet: O(1)
//   follow/unfollow: O(1) avg
//   getNewsFeed: O(P) worst-case (scan from most recent until 10 found)
// Space Complexity: O(P + F)  (P = #tweets stored, F = #follow relationships)

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows; // follower -> set of followees
    vector<pair<int,int>> posts;                    // (userId, tweetId) in time order

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int count = 0;

        for (int i = (int)posts.size() - 1; i >= 0 && count < 10; i--) {
            int author = posts[i].first;
            if (author == userId || follows[userId].count(author)) {
                result.push_back(posts[i].second);
                count++;
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
