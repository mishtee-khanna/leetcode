#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Twitter {
private:
    // Structural node to track tweets as a singly linked list per user
    struct Tweet {
        int id;
        int time;
        Tweet* next;
        Tweet(int tweetId, int timestamp) : id(tweetId), time(timestamp), next(nullptr) {}
    };

    // Min-heap structure to pull the absolute highest timestamps first
    struct TweetComparator {
        bool operator()(const Tweet* a, const Tweet* b) {
            return a->time < b->time;
        }
    };

    int timestamp;
    unordered_map<int, unordered_set<int>> following; // followerId -> set of followeeIds
    unordered_map<int, Tweet*> userTweets;            // userId -> head of tweet linked list

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        Tweet* newTweet = new Tweet(tweetId, timestamp);
        
        // Push to the front of the user's tweet history linked list
        newTweet->next = userTweets[userId];
        userTweets[userId] = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*, vector<Tweet*>, TweetComparator> maxHeap;
        
        // 1. Collect the user's own top tweet
        if (userTweets[userId] != nullptr) {
            maxHeap.push(userTweets[userId]);
        }
        
        // 2. Collect the top tweets from everyone they follow
        for (int followeeId : following[userId]) {
            if (userTweets[followeeId] != nullptr) {
                maxHeap.push(userTweets[followeeId]);
            }
        }
        
        vector<int> feed;
        // 3. Extract the 10 most recent global tweets using K-way merge
        while (!maxHeap.empty() && feed.size() < 10) {
            Tweet* curr = maxHeap.top();
            maxHeap.pop();
            
            feed.push_back(curr->id);
            
            // If this user has older tweets, move to the next node in their list
            if (curr->next != nullptr) {
                maxHeap.push(curr->next);
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter* twitter = new Twitter();
    
    // User 1 posts a tweet (id = 5)
    twitter->postTweet(1, 5);
    
    // User 1 checks their feed -> should return [5]
    vector<int> feed1 = twitter->getNewsFeed(1);
    cout << "Feed 1: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;
    
    // User 1 follows user 2
    twitter->follow(1, 2);
    
    // User 2 posts a tweet (id = 6)
    twitter->postTweet(2, 6);
    
    // User 1 checks their feed -> should return [6, 5]
    vector<int> feed2 = twitter->getNewsFeed(1);
    cout << "Feed 2: ";
    for (int id : feed2) cout << id << " ";
    cout << endl;
    
    // User 1 unfollows user 2
    twitter->unfollow(1, 2);
    
    // User 1 checks feed -> should return [5]
    vector<int> feed3 = twitter->getNewsFeed(1);
    cout << "Feed 3: ";
    for (int id : feed3) cout << id << " ";
    cout << endl;
    
    return 0;
}