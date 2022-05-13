/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// @lc code=start


typedef pair<int, int> PAIR;
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
}
struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second < rhs.second;
    }
};
class Twitter {

public:
    Twitter() : post_id(0), id_list({}), post_list({}), follower_list({}) {}

    void postTweet(int userId, int tweetId) {
        if (id_list.empty() ||
            (find(id_list.begin(), id_list.end(), userId) == id_list.end())) {
            id_list.push_back(userId);
        }
        if (post_list.find(userId) == post_list.end()) {
            post_list[userId] = vector<map<int, int>>();
        }
        map<int, int> m;
        m[tweetId] = post_id++;
        post_list[userId].push_back(m);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> posts;
        vector<int> id;
        id.push_back(userId);
        for (auto i: follower_list[userId]) {
            id.push_back(i);
        }
        for (auto i: id) {
            for (auto p: post_list[i]) {
                posts.insert(p.begin(), p.end());
            }
        }
        vector<PAIR> name_score_vec(posts.begin(), posts.end());
        sort(name_score_vec.begin(), name_score_vec.end(),
             CmpByValue());
        for (auto i: name_score_vec) {
            res.push_back(i.first);
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (follower_list.find(followerId) == follower_list.end()) {
            follower_list[followerId] = vector<int>();
        }
        if (find(follower_list[followerId].begin(),
                 follower_list[followerId].end(),
                 followeeId) == follower_list[followerId].end()) {
            follower_list[followerId].push_back(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (follower_list.find(followerId) == follower_list.end()) {
            return;
        }
        auto follower = &follower_list[followerId];
        auto it = find(follower->begin(),
                         follower->end(),
                       followeeId);
        if (it == follower->end()) {
            return;
        }
        follower->erase(it);
    }

private:
    int post_id;
    vector<int> id_list;
    map<int, vector<map<int, int>>> post_list;
    map<int, vector<int>> follower_list;
};

int main() {
    Twitter *obj = new Twitter();
    obj->postTweet(1, 2);
    obj->postTweet(2, 4);

    cout << endl << "1==============" << endl;
    for (auto i: obj->getNewsFeed(1)) {
        cout << i << " ";
    }

    obj->follow(1, 2);
    cout << endl << "2==============" << endl;
    for (auto i: obj->getNewsFeed(1)) {
        cout << i << " ";
    }
    obj->unfollow(1, 2);

    cout << endl << "3==============" << endl;
    for (auto i: obj->getNewsFeed(1)) {
        cout << i << " ";
    }
}
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
